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
   
   -- project a new type 
      - var nameDesc = from p in products select new { p.Name, p.Description };
         - NO way of knowing the underlying data type
   
   -- get count 
      - int numb = (from g in currentVideoGames where g.Length > 6 select g).Count();
  
   -- Reversing Result Sets 
      - var prod in allProducts.Reverse()
      
   -- LINQ As a Better Venn Diagramming Tool
      - 并集交集补集之类的 
      - .except  .intersect   .union  .concat
      
      - remove duplicate
         - .distinct()
         
      - aggregate
      
   -- Building Query Expressions Using the Enumerable Type and Lambda Expressions
         
      - string array 本身自己就有几个自带的function 
         - var subset = currentVideoGames.Where(game => game.Contains(" "))
            .OrderBy(game => game).Select(game => game);
     
   后面还可以有， Building Query Expressions Using the Enumerable Type and Anonymous Methods
   - Building Query Expressions Using the Enumerable Type and Raw Delegates
   一个比一个繁琐，但是这些事linq的底层实现。
         
         
         
         
         
         
      
      
      
      
      
      
      
      
      
   
