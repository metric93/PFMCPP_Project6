/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
        if (a != nullptr && b != nullptr)
        {
            //Compare the Value (float type) from the two Pointers and return the smaller one
            if( a->value < b->value ) return a; //compare the two value contained in the    pointers to Type "T" created above
            if( a->value > b->value ) return b;
        }
        return nullptr; //if none of the if statements matched return a nullptr
    }
};

struct U
{
    U(){std::cout << "New Object of Type U has been created" << std::endl;}
    
    float uSetPoint { 0 }, uProcessVariable { 0 };

    float updateLogic(float* newValue)      //12
    {
        if (newValue == nullptr)
        {
            std::cout << "Detected Nullpointer!" << std::endl;
            return 0.0f; 
        }

        std::cout << "U's uSetPoint value: " << this->uSetPoint << std::endl;
        this->uSetPoint = *newValue; //Acess the uSetPoint float that is part of the Pointer to a Type U* named that
        std::cout << "U's uSetPoint updated value: " << this->uSetPoint << std::endl;

        while( std::abs(this->uSetPoint - this->uProcessVariable) > 0.001f)
        {
            this->uProcessVariable += 0.5f ;
            std::cout << this->uProcessVariable << std::endl;
        }
        std::cout << "U's uProcessVariable updated value: " << this->uProcessVariable << std::endl;
        return this->uProcessVariable * this->uSetPoint;
    }
};

struct MyUpdater
{
    static float updateLogic(U* that, float* newValue )        //10
    {
        if (that == nullptr || newValue == nullptr)
        {
            std::cout << "Detected Nullpointer!" << std::endl;
            return 0.0f; //returns 0.0f if a nullponter was detected
        }

        std::cout << "U's uSetPoint value: " << that->uSetPoint << std::endl;
        that->uSetPoint = *newValue; //Acess the uSetPoint float that is part of the Pointer to a Type U* named that
        std::cout << "U's uSetPoint updated value: " << that->uSetPoint << std::endl;
        while( std::abs(that->uProcessVariable - that->uSetPoint) > 0.001f )
        {    
            /*
            write something that makes the distance between that->uProcessVariable and that->uSetPoint get smaller
            */
            that->uProcessVariable += 0.5f ;
            std::cout << that->uProcessVariable << std::endl;
        }
        std::cout << "U's uProcessVariable updated value: " << that->uProcessVariable << std::endl;
        return that->uProcessVariable * that->uSetPoint;
        
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T uSetPoint( 5 , "thefirstT" );                                             //6
    T uProcessVariable( 15 , "thesecondT" );                                             //6

    
    CompareFunc f;                                            //7
    //Using the Adress of Operator to match the functions arguments which are two Pointers to the Type "T" (created via struct)
    //Assignig to a Pointer (type "auto") as the Function outputs the adress of a Pointer to Type "T"
    auto* smaller = f.compare( &uSetPoint , &uProcessVariable);                              //8

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
    std::cout << "[static func] myUType's multiplied value: " << std::endl << MyUpdater::updateLogic( &myUType , &updatedValue ) << std::endl;                  //11
    

    //Changing the updatedValue via the function in the created object of Type U
    U myUTypeTwo;
    std::cout << "[member func] myUTypeTwo's multiplied values: " << std::endl << myUTypeTwo.updateLogic( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
