##########     Core C# Programming Constructs, Part II 

-- parameter modifier
  - none, pass by value
  - out, pass by ref, if fail to assgin, compiler error
    - can change multiple
      - static void FillTheseValues(out int a, out string b, out bool c) 
    - no need to initilize, since must assign a value in out
      
  - ref, pass by ref, no compiler error 
    - must initilize a value 
    
  - parameter, 传 arrary
    - the caller sends in a strongly typed array or a comma-delimited list of items.
      - static double CalculateAverage(params double[] values) 
    - must be the final argument in the list  

   -- Defining Optional Parameters
      - static void EnterLogData(string message, string owner = "Programmer") 
      - the optional parameter must be known at compiler time 
      - always at end of list 
 
    -- using named parameter
      - parameter的位置无所谓，用名字来表示
        - static void DisplayFancyMessage(ConsoleColor textColor, ConsoleColor backgroundColor, string message) 
        - usage:  DisplayFancyMessage(message: "Wow! Very Fancy indeed!",  textColor: ConsoleColor.DarkRed, 
       - 放在正常的parameter之后
       
       
       pending -- Understanding C# Arrays
