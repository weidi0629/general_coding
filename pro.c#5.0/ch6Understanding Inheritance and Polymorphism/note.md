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
      
      
-- pending Understanding Abstract Classes
    
