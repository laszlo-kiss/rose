// This is a copy of test2013_223.C (before modifications).
template<typename T>
void foo();

// Make this a declaration so that we can call it below.
template<> void foo<int>();

class bar 
   {
     void foo() 
        {
       // The issue here is NOTE that that has not yet been an instantiation.
       // But that a declaration with the same name as the template associated with
       // the template instantiation forces the requirement for name qualification.
          ::foo<int>();
        }
   };

