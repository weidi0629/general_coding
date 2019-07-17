###  Inheritance  ###

-- c#不允许multiple inheritence, 但可以用interface代替

-- The sealed Keyword
  - 不允许被derive 
  - C# structures are always implicitly sealed 
  
-- Constructor
  - using base  
    - why? the default constructor of a base class is called automatically before the logic of the derived constructor is executed
      public Manager(string fullName, int age, int empID,
                    float currPay, string ssn, int numbOfOpts)
                    : base(fullName, age, empID, currPay, ssn)
    - 记得redefine default const, if you define the custom cont 
    
    
-- C#’s Polymorphic
  -- base class, 如果会可能override, 加virtual 关键词 
    - public virtual void GiveBonus
  -- subclass 要加 override 关键词 
    -  public override void GiveBonus(float amount)
    - 仍可以用base里面的method,只要加 base. 就行 
      -base.GiveBonus(amount); 
  -- Sealing Virtual Members
    - public override sealed void GiveBonus(float amount)
      - derived class 就不能再extend这个方程了 
            
  -- Understanding Abstract Classes
    - abstract - 加了之后就不能实例化了
      - abstract partial class Employee
    
  -- Understanding the Polymorphic Interface
    - 在base class 中定义abstract method, 就一定要求derived class implement
      public abstract void Draw();
    - Abstract methods can only be defined in abstract classes
    
  -- member shadowing     
    - 用 new 来把base的定义藏起来
  
  -- Understanding Base Class/Derived Class Casting Rules
    -- 高一级的class可以take 低一级的class -- c++里重要的oop知识点
      - Employee moonUnit = new Manager("
      - object frank = new Manager
    -- 用法：
      - static void GivePromotion(Employee emp) 所有employee的derived class 都可以进去 
    
    - explicit cast
      - 原因： object frank = new Manager 因为是object， 所以不能传进 GivePromotion(Employee emp)
      - explicit cast用法： (ClassIWantToCastTo)referenceIHave
        - GivePromotion((Manager)frank);
    
    
  -- The C# as Keyword
    -- as 可以查obj是否是null 
    
    -- is 可以比较obj，返回true false 
      - if (emp is SalesPerson)
      
    -- overrideing system.object.ToString()
      - every obj derived from system.Object
        - 对于debug来说非常方便 
        
    -- overrideing system.object.Equals()
      - make safty check 保证比较的obj是正确的
        - if (obj is Person && obj != null)
        - 可以用ToString做个shortcut 
      
    -- Overriding System.Object.GetHashCode()
        - 可以得到一个代表obj的id 
        - 可以使用你的class里有唯一性的string，比如ssn
          -  public override int GetHashCode(){
                return SSN.GetHashCode(); // string有内置的GetHashCode()
      
    -- The Static Members of System.Object
      - object.Equals(p3, p4)); // object level 
      - object.ReferenceEquals(p3, p4));  // ref level 
      
      
      
      
      
    
    
    
    
    
