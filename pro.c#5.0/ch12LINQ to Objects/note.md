-- Language Integrated Query (LINQ) 
   - 类似于一个总的借口，取得各个地方的data： 数据库，in memory, XML
   
-- Applying LINQ Queries to Primitive Arrays
   - always want to make use of implicit typing when capturing the results of a LINQ query
   
   -- 如果你要return 一个 LINQ type
       - 可以strong type 参数为  IEnumerable<string>, var是不能return的 
       
       - use of immediate execution
         - return theRedColors.ToArray();
      
       
    -- Applying LINQ Queries to Collection Objects
      - 就当一般的type用
         - var fastCars = from c in myCars where c.Speed > 55 select c;
   
    -- Applying LINQ Queries to Nongeneric Collections
      - using the generic Enumerable.OfType<T>() extension method         
         - // Transform ArrayList into an IEnumerable<T>-compatible type.
            var myCarsEnum = myCars.OfType<Car>();
         -  // Create a query expression targeting the compatible type.
            var fastCars = from c in myCarsEnum where c.Speed > 55 select c;
   
       - Filtering Data Using OfType<T>()
         - 因为non-generic type可以是接受所有的object，用Oftype<T>可以过滤掉其他的type
            - var myInts = myStuff.OfType<int>();
   
-- investigating the C# LINQ Query Operators
   
   pending Basic Selection Syntax 搞了一个product info的array
   
   
   
