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
    {}
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
    U(){std::cout << "U Type has been instantaiated" << std::endl;}
    
    float uValueOne { 0 }, uValueTwo { 0 };

    float updateLogic(float* newValue)      //12
    {
        if (newValue == nullptr)
        {
            std::cout<<"Detected Nullpointer!" << std::endl;
            return this->uValueOne * this->uValueTwo; //in this case we use this-> in order to point to the Value of the Instantation that the function belongs to
        }

        while( std::abs(this->uValueOne - this->uValueTwo) > 0.001f)
        {
            this->uValueTwo += -0.1f ;
        }
        std::cout << "U's uValueTwo updated value: " << this->uValueTwo << std::endl;
        return this->uValueTwo * this->uValueOne;
    }
};

struct MyUpdater
{
    static float updateLogic(U* that, float* newValue )        //10
    {
        std::cout << "U's uValueOne value: " << that->uValueOne << std::endl;
        that->uValueOne = *newValue; //Acess the uValueOne float that is part of the Pointer to a Type U* named that
        std::cout << "U's uValueOne updated value: " << that->uValueOne << std::endl;
        while( std::abs(that->uValueTwo - that->uValueOne) > 0.001f )
        {    
            /*
             write something that makes the distance between that->uValueTwo and that->uValueOne get smaller
             */
            that->uValueTwo += -0.1f ;
        }
        std::cout << "U's uValueTwo updated value: " << that->uValueTwo << std::endl;
        return that->uValueTwo * that->uValueOne;
    }
};
        
int main()
{
    T uValueOne( 5 , "thefirstT" );                                             //6
    T uValueTwo( 15 , "thesecondT" );                                             //6

    
    CompareFunc f;                                            //7
    //Using the Adress of Operator to match the functions arguments which are two Pointers to the Type "T" (created via struct)
    //Assignig to a Pointer (type "auto") as the Function outputs the adress of a Pointer to Type "T"
    auto* smaller = f.compare( &uValueOne , &uValueTwo);                              //8

    //Fetch the Name Value from the pointed to Adress, as nullptr is a valid return from the function make an if statment to detect it
    if (smaller == nullptr) //9
    {
        std::cout << "Nullpointer Detected" << std::endl;
    }
    else
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; 
    }




    //Changing the updatedValue via the function in the MyUpdate Objcet
    U myUType;
    float updatedValue = 5.f;
    std::cout << "[static func] myUType's multiplied values: " << MyUpdater::updateLogic( &myUType , &updatedValue ) << std::endl;                  //11
    

    //Changing the updatedValue via the function in the created object of Type U
    //U myUTypeTwo;
    //std::cout << "[member func] myUTypeTwo's multiplied values: " << myUTypeTwo.updateLogic( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
