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
    
    
    pending Keeping Family Secrets: The protected Keyword
