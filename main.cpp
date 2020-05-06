/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    //Initialize "value" and "name" 
    float value;
    std::string name;

    T(int v, const char* myName) :  //1 //Constructs that assigns Constructor Parameters to variables above
    value (v), //2 
    name (myName)//3
    {};
};

struct CompareFunc                                //4
{
    T* compare(T* a, T* b) //5
    {
        //Compare the Value (float type) from the two Pointers and return the smaller one
        if( a->value < b->value ) return a; //compare the two value contained in the pointers to Type "T" created above
        if( a->value > b->value ) return b;
        return nullptr; //if none of the if statements matched return a nullptr
    }
};

struct U
{
    float MyTOne { 0 }, MyTTwo { 0 };
    <#returnType#> <#memberFunction#>(<#type name#>* <#updatedValue#>)      //12
    {
        
    }
};

struct <#structname2#>
{
    static <#returntype#> <#staticFunctionA#>(U* that, <#type name#>* <#updatedValue#> )        //10
    {
        std::cout << "U's MyTOne value: " << that->MyTOne << std::endl;
        that->MyTOne = <#updatedValue#>;
        std::cout << "U's MyTOne updated value: " << that->MyTOne << std::endl;
        while( std::abs(that->MyTTwo - that->MyTOne) > 0.001f )
        {
            /*
             write something that makes the distance between that->MyTTwo and that->MyTOne get smaller
             */
            that->MyTTwo += ;
        }
        std::cout << "U's MyTTwo updated value: " << that->MyTTwo << std::endl;
        return that->MyTTwo * that->MyTOne;
    }
};
        
int main()
{
    T MyTOne( 5 , "thefirstT" );                                             //6
    T MyTTwo( 2 , "thesecondT" );                                             //6
    
    CompareFunc f;                                            //7
    //Using the Adress of Operator to match the functions arguments which are two Pointers to the Type "T" (created via struct)
    //Assignig to a Pointer (type "auto") as the Function outputs the adress of a Pointer to Type "T"
    auto* smaller = f.compare( &MyTOne , &MyTTwo);                              //8
    //Fetch the Name Value from the pointed to Adress, as nullptr is a valid return from the function make an if statment to detect it
    if (smaller == nullptr) //9
    {
        std::cout << "Nullpointer Detected" << std::endl;
    }
    else
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; 
    }
    U <#name3#>;
    float updatedValue = 5.f;
    std::cout << "[static func] <#name3#>'s multiplied values: " << <#structname2#>::<#staticFunctionA#>( , ) << std::endl;                  //11
    
    U <#name4#>;
    std::cout << "[member func] <#name4#>'s multiplied values: " << <#name4#>.<#memberFunction#>( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
