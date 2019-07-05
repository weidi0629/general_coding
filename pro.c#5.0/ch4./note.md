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
        
    -- Understanding C# Arrays
      - 可以直接初始 bool[] boolArray = { false, false, true }; 
      - 因为system obj是所有obj的源，所以object[] myObjects = new object[4] 这种什么都可以装：  myObjects[0] = 10;myObjects[1] = false;

      -- Arrays As Arguments or Return Values
        - void PrintArray(int[] myInts) 


    -- Understanding the enum Type
      - 可以改变enum type: enum EmpType : byte
        - 可以用Enum.GetUnderlyingType()来取得它的type
      - enum.to_string可以显示enum的名字 
      -  GetValues() return a system.array, each element is name/value pair
        - Array enumData = Enum.GetValues(e.GetType());
        
    -- Understanding the Structure Type 
       - well suited for modeling mathematical, geometrical, and other “atomic” entities
       - no inheritance 
       - using default constructor -- all parameters are assign to defualt values 
          - Point p1 = new Point(); 
          
    -- Understanding Value Types and Reference Types
      - structure defirved from system.valueType - value based! 
      - it's on the stack 
        - stack - lift time short,
        - heap - monitro by many factors, garbage-collected 
      - when outof the scope, remove quickly 
      - 如果是class 就都是ref type 重要！ 
      - 如果structure里面包含了class, copy之后，里面的class会指向同一个ref (i.e., a shallow copy)
    
    -- Passing Reference Types by Value 
      -  a copy of the reference to the caller’s object
        -  void SendAPersonByValue(Person p) 像这种方程是会改变原来的值的
    
    -- Passing Reference Types by Reference 
      -完全改掉了，并且还能重新赋值
        - void SendAPersonByReference(ref Person p) {
              p = new Person("Nikki", 999); 

    -- Understanding C# Nullable Types
      - null: estabilish an empty object reference 
      - ? only applied to value type 
         - int? nullableInt = 10;
         - 就是说这个值可以是null的，访问database时好用
      - ?? - 如果是null的就赋一个默认值
         - int myData = dr.GetIntFromDatabase() ?? 100;
    
    
    
    
    
    
    
    







