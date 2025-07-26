import Test.HUnit
import qualified DoOp as D
import System.Environment (withArgs)
import System.Exit (ExitCode(..))
import System.IO.Silently (capture)
-- Test case 1: The element is in the list
testElementInList :: Test
testElementInList = TestCase $ do
    assertEqual "for myElem 3 [1, 2, 3, 4], " True (D.myElem 3 [1, 2, 3, 4])

-- Test case 2: The element is not in the list
testElementNotInList :: Test
testElementNotInList = TestCase $ do
    assertEqual "for myElem 5 [1, 2, 3, 4], " False (D.myElem 5 [1, 2, 3, 4])

-- Test case 3: The list is empty
testEmptyList :: Test
testEmptyList = TestCase $ do
    assertEqual "for myElem 3 [], " False (D.myElem 3 [])

-- Test case 4: The element is the first element in the list
testFirstElement :: Test
testFirstElement = TestCase $ do
    assertEqual "for myElem 1 [1, 2, 3, 4], " True (D.myElem 1 [1, 2, 3, 4])

-- Test case 5: The element is the last element in the list
testLastElement :: Test
testLastElement = TestCase $ do
    assertEqual "for myElem 4 [1, 2, 3, 4], " True (D.myElem 4 [1, 2, 3, 4])

testElement :: Test
testElement = TestList [testElementInList, testElementNotInList, testEmptyList, testFirstElement, testLastElement]


--- safe div test 
testSafeDivNonZero :: Test
testSafeDivNonZero = TestCase $ do
    assertEqual "for safeDiv 4 2, " (Just 2) (D.safeDiv 4 2)

-- Test case: Division by zero
testSafeDivByZero :: Test
testSafeDivByZero = TestCase $ do
    assertEqual "for safeDiv 4 0, " Nothing (D.safeDiv 4 0)

-- Group all test cases
testSafeDiv :: Test
testSafeDiv = TestList [testSafeDivNonZero, testSafeDivByZero]



runMainWithArgs :: [String] -> IO (String, ExitCode)
runMainWithArgs args = do
  (output, result) <- capture $ withArgs args (D.main >> return ExitSuccess)
  return (output, result)

-- Test case: Incorrect number of arguments
testMainIncorrectArgs :: Test
testMainIncorrectArgs = TestCase $ do
  (_, result) <- runMainWithArgs ["1", "+"]
  assertEqual "for main with incorrect args" (ExitFailure 84) result

-- Test case: Invalid operator
testMainInvalidOperator :: Test
testMainInvalidOperator = TestCase $ do
  (_, result) <- runMainWithArgs ["1", "x", "2"]
  assertEqual "for main with invalid operator" (ExitFailure 84) result

-- Test case: Division by zero
testMainDivByZero :: Test
testMainDivByZero = TestCase $ do
  (_, result) <- runMainWithArgs ["1", "/", "0"]
  assertEqual "for main with division by zero" (ExitFailure 84) result

-- Test case: Valid addition
testMainValidAddition :: Test
testMainValidAddition = TestCase $ do
  (output, result) <- runMainWithArgs ["1", "+", "2"]
  assertEqual "for main with valid addition" ExitSuccess result
  assertEqual "output for valid addition" "3\n" output

-- Test case: Valid subtraction
testMainValidSubtraction :: Test
testMainValidSubtraction = TestCase $ do
  (output, result) <- runMainWithArgs ["5", "-", "3"]
  assertEqual "for main with valid subtraction" ExitSuccess result
  assertEqual "output for valid subtraction" "2\n" output

-- Group all test cases
testMain :: Test
testMain = TestList [testMainIncorrectArgs, testMainInvalidOperator, testMainDivByZero, testMainValidAddition, testMainValidSubtraction]


-- Run all tests
main :: IO Counts
main = runTestTT $ TestList [testElement, testSafeDiv, testMain]
