-- Allocating Objects with the new Keyword  
  - using new to allocate into memory
  - 如果只是单 decleare 一下，其实是 declares a reference to a yet-to-be-determined Carobject
    - Car myCar; 
  
-- Understanding Constructors
  - 如果define custom cont, 就一定要define default ctor 
  
  -- use this for constructor chain 
    - 一个总的constructor接受很多parameter. 少的通过this 传默认值进去
      - public Motorcycle(int intensity) 
          : this(intensity, "") {}
          - 最后控制还是回到这个 ctor
  
  -- Understanding the static Keyword 
    - static constructor only call once before use 
    - static class only contain static member 
    - internal - only accessed by current assembly 
    - in default, implicitly private and implicitly internal
      - 如果要让别的module invoke 这个class, 要把这个class 定义成 public

  -- The First Pillar: C#’s Encapsulation Services
    - public member 不能很好地植入business logic, like book page 
    -- tranditional method
      - set/muator method 
    
    -- Encapsulation Using .NET Properties
      - type就是里面要搞的type
      - 定义的时候没有括号
        - public int ID // Note lack of parentheses. 
          {
            get { return empID; }
            set { empID = value; }
          }
        - value是内置的token，表示imcomming value 
        - can ben operate like this: obj.ID++; 
      - the only time when you directly make reference to the underlying private piece of data is within the property itself.

    -- Read-Only and Write-Only Properties
      - readonly - simply omit set part
    -- Understanding Automatic Properties 
      - 就基本的get/set 
      - public string PetName { get; set; }
        - 在compiler time会自动generate, 但具体是什么名字不知道的--important, 重要 
      - default value 
        - a safe default value
        - 如果是class就是null 
          - 需要在constructor里初始这个obj. page 198
    
    --  Working with Constant Field Data
      - const is implicitly static
      - the initial value assigned to the constant must be specified at the time you define the constant
    
    -- Understanding Read-Only Fields
      - 跟const 一样： cannot be changed after the initial assignment.
      - 跟const 不一样： assign的value可以在runtime 赋值，所以可以加在constructor里面
      -- 跟const 不一样： 不是implicitly const的 
    
    -- Understanding Partial Types
      - partial class Employee {.. 可以把class分别写进好几个文件中 
      
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

