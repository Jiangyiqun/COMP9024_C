# COMP9024 Assignment 2 autotest

## Quick start

### 1. Download autotest

`git clone https://github.com/Jiangyiqun/autotest.git`

### 2. Put your code in

Copy all your code into `/autotest/submit`

### 3. Run autotest

Maximum your terminal windows and run `/autotest/autotest.sh`

## User Manual

you can open README.md in your /autotest folder to see this manual at any time.

```
Usage: autotest [OPTION]
Test COMP9024 assignment 2

test modules separately
  p           test pagerank only
  i           test invertedIndex only
  s           test searchPagerank only

by default, full result only shows when failed
  f           always show full result

In order to get the most recently added test cases
  u           manually update this test script

all arguments above can be used together
```

## How to add your test case

For example, you want to add another test case called inverted_test99, you need to do two things:

### 1. Add a folder called `inverted_test99`, includes:

- collection.txt
- url??.txt
- invertedIndex.exp

### 2. Add new line of code in `autotest.sh`, like:

```shell
################################### modify your test case here ###################################
            testinverted inverted_test01
            testinverted inverted_test02
            testinverted inverted_test03
            testinverted inverted_test99
################################### modify your test case here ###################################
```

## Compatibility

![](image/compatible-with-linux-logo.png)
![](image/incompatible-with-mac-logo.png)
![](image/incompatible-with-windows-logo.png)
