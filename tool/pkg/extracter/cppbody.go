package extracter

import (
  "bufio"
  "os"
  "fmt"
  "strings"
)

const (
  docCommentBegin string = "/**" 
  docCommentEnd string = "*/"
)

func ReadAll(filepath string) ([]string, error) {
  file, err := os.Open(filepath)
  if err != nil {
    return nil, err
  }
  defer file.Close()

  sc := bufio.NewScanner(file)
  rows := make([]string, 0, 64)

  for sc.Scan() {
    rows = append(rows, sc.Text())
  }

  if err := sc.Err(); err != nil {
    return nil, err
  }

  return rows, nil
}

func CppBody(filepath string) ([]string, error) {
  rows, err := ReadAll(filepath)
  if err != nil {
    return nil, err
  }
  bodyBegin := searchBodyBegin(rows)
  bodyEnd := searchBodyEnd(rows)

  if bodyBegin < bodyEnd {
    return rows[bodyBegin : bodyEnd], nil
  } else {
    return nil, fmt.Errorf("Error in '%s': maybe not found doc comment", filepath)
  }
}

func searchBodyBegin(rows []string) int {
  i := 0
  foundDocBegin := false
  for ;i < len(rows); i++ {
    if !foundDocBegin {
      foundDocBegin = foundDocBegin || strings.Contains(rows[i], docCommentBegin)
    } else if strings.Contains(rows[i], docCommentEnd) {
      i++
      break
    }
  }
  return i
}

func searchBodyEnd(rows []string) int {
  i := len(rows) - 1
  for i >= 0 && strings.TrimSpace(rows[i]) == "" {
    i--
  }
  return i + 1
}
