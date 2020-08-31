package main

import (
  "os"
  "os/user"
  "path/filepath"
  "strings"
  "fmt"
  "log"
  "flag"
  "./pkg/extracter"
)

var (
  includeMarker string
  processTargetFileName string
)

func init() {
  flag.StringVar(&includeMarker, "include-marker", "@include", "include-directive marker to be expanded.")
}

func main() {
  parseAndCheckFlag()

  rows, err := extracter.ReadAll(processTargetFileName)
  if err != nil {
    log.Fatal(err)
  }

  expandedRows, err := ExpandIncludeDirective(rows)
  if err != nil {
    log.Fatal(err)
  }

  for _, row := range expandedRows {
    fmt.Println(row)
  }
}

func parseAndCheckFlag() {
  flag.Parse()

  if len(flag.Args()) <= 0 {
    fmt.Fprintf(os.Stderr, "Error: please give one processTargetFileName.\n")
    fmt.Fprintf(os.Stderr, "Usage:\n")
    fmt.Fprintf(os.Stderr, " $ %s <filename> [-include-marker <marker>] [-help]\n", os.Args[0])
    os.Exit(1)
  }

  processTargetFileName = ExpandTildeDir(flag.Arg(0))

  if !Exists(processTargetFileName) {
    log.Fatalf("Error: '%s': No such file.", processTargetFileName)
    os.Exit(2)
  }
}

func ExpandIncludeDirective(rows []string) ([]string, error) {
  processTargetDir := filepath.Dir(processTargetFileName)
  errMsg := ""

  res := make([]string, 0, len(rows) * 4)

  for lineNumber, row := range rows {
    if idx := strings.Index(row, includeMarker); idx != -1 {

      includeFilePath := ExpandTildeDir(strings.TrimSpace(row[idx + len(includeMarker) + 1 :]))
      if !filepath.IsAbs(includeFilePath) {
        includeFilePath = filepath.Join(processTargetDir, includeFilePath)
      }

      bodyRows, err := extracter.CppBody(includeFilePath)
      if err != nil {
        errMsg += fmt.Sprintf("  %s:%d: '%s': Read failed.\n", processTargetFileName, lineNumber, row)
      } else {
        for _, bodyRow := range bodyRows {
          res = append(res, bodyRow)
        }
      }

    } else {
      res = append(res, row)
    }
  }

  if errMsg != "" {
    return nil, fmt.Errorf("Expantion Error:\n%s", errMsg)
  } else {
    return res, nil
  }
}

func Exists(filename string) bool {
    _, err := os.Stat(filename)
    return err == nil
}

func ExpandTildeDir(path string) string {
  usr, _ := user.Current()
  homedir := usr.HomeDir
  if path == "~" {
    return homedir
  } else if strings.HasPrefix(path, "~/") {
    return filepath.Join(homedir, path[2:])
  } else {
    return path
  }
}
