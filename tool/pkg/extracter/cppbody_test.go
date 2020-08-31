package extracter

import (
  "testing"
  "os"
  "reflect"
)

func TestCode(t *testing.T) {
  dir, _ := os.Getwd()
  targetCppFile := dir + "/example.txt"

  println("targetCppFile:", targetCppFile)

  body, _ := CppBody(targetCppFile)

  expected := []string { "#define all(x) std::begin(x), std::end(x)", "#define rall(x) std::rbegin(x), std::rend(x)" }

  if !reflect.DeepEqual(body, expected) {
    t.Fatalf("testing by '%s': extracted body not matched.", targetCppFile)
  }
}
