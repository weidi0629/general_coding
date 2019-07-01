-- all data members and all methods must be contained within a type definition.

-- the class that defines the Main() method is termed the application object.

-- Environment class
  - 告诉你run main的参数
    - string[] theArgs = Environment.GetCommandLineArgs();
    - 多少盘符 Environment.GetLogicalDrives())
    - Environment.ProcessorCount; Environment.OSVersion; Environment.Version
    
-- Formatting Numerical Data
  - 不同字符不同含义，比如 c 是 currency, 完整的表 page 81
     - Console.WriteLine("c format: {0:c}", 99999);
  - string.Format() 也可以用的 
    - string userMessage = string.Format("100000 in hex is {0:x}",


-- System Data Types and Corresponding C# Keywords
  -  C# data type keywords are actually shorthand notations for full-blown types in the Systemnamespace
  - declare 之后最好赋值，不然要报错的
  
  -- Intrinsic Data Types and the new Operator 
    - new: automatically sets the variable to its default value
      - int i = new int();
      
   - Members of System.Boolean     
     - bool.FalseString, bool.TrueString: yield "True" "False"  
     
   - Parsing Values from String Data
      - 每个type都可以从string parse
        - double d = double.Parse("99.884");
        
        
   -- The System.Numerics.dll Assembly 超级大的数 
      - 一般用parse： BigInteger.Parse("9999999999999999999999999999999999999999999999"); 
      
      
 -- Working with String Data 
  - escape character \ 
    - \a 发出beep声音 
    
 -- Defining Verbatim Strings 
    - 前面加 @
    - you disable the processing of a literal’s escape characters and print out a string as is.
    - 双引号 单引号 \\都可以打出来 
    
 -- Strings and Equality 
    - 一般的操作是建立一个copy of original string, 如果操作不好就会有资源浪费。 
    
    -- The System.Text.StringBuilder Type - more efficient way 
      - 直接操作！ 快
    
  -- Narrowing and Widening Data Type Conversions
    - narrow 会报错 
      - explicitly cast short answer = (short)Add(numb1, numb2);
      - using checked keyword to check if loss data  
      - byte sum = checked((byte)Add(b1, b2)) 跟 exception 合用 
      - Setting Project-Wide Overflow Checking
         - advanced botton 
      - unchecked 
        - 如果全局设定了overflow不行，一小部分是可以的，就用 unchecked
        
  -- Understanding Implicitly Typed Local Variables - var 
    - restrictions and limitation
       -implicit typing applies only to local variables in a method or property scope
      - no return type, parameters, field data of a custom type
      - must assign some value 
      
      -- Implicit Typed Data Is Strongly Typed Data
        - 一旦指定是这个type就不能换了。 
    
      -- when/how to use 
         - LINQ
    
    
    
    
    
    
    
    
    
    
    
