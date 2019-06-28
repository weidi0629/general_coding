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
    
pending Strings and Equality 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
