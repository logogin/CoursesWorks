#include <iostream.h>

/************************************************************************/
/*																		*/
/*						First Tamplate Class							*/
/*																		*/
/************************************************************************/

template <class DataType>
class Types
{
  public:
    /*		Constructor		*/
    Types(const DataType DTValue = 0)
    {
        m_pTypes = 0;
        m_Type = DTValue;
    }

    /*		Linking New Object		*/
    void NewObject(const DataType DTValue = 0)
    {
        m_pTypes = new Types<DataType>(DTValue);
    }

    /*		Returning Pointers Address		*/
    Types<DataType> *GetPtr() const
    {
        return m_pTypes;
    }

    /*		Destructor		*/
    ~Types()
    {
        if (m_pTypes)
        {
            delete m_pTypes;
        }
    }

  private:
    Types *m_pTypes;
    DataType m_Type;
};

/************************************************************************/
/*																		*/
/*						Second Tamplate Class							*/
/*																		*/
/************************************************************************/

template <class DataType, unsigned short usMaxObjectsNumber>
class DataChain
{
  public:
    /*		Constructor		*/
    DataChain(const DataType DTValue = 0)
        : m_Type(DTValue)
    {
        m_pType = &m_Type;

        m_sTypeCounter++;
    }

    /*		Creating New Object in the Chain		*/
    void NewObject(const DataType DTValue = 0)
    {
        if (m_sTypeCounter < usMaxObjectsNumber)
        {
            m_pType->NewObject(DTValue);
            m_pType = m_pType->GetPtr();

            m_sTypeCounter++;
        }
        else
        {
            cout << "Can not Open New Object"
                 << endl;
        }
        cout << "You have "
             << m_sTypeCounter
             << " Open Objects."
             << endl;
    }

    /*		Destructor		*/
    ~DataChain()
    {
        m_pType = 0;
    }
    static unsigned short m_sTypeCounter;

  private:
    Types<DataType> m_Type;
    Types<DataType> *m_pType;
};

/************************************************************************/
/*																		*/
/*						Static Parameter Initialization					*/
/*																		*/
/************************************************************************/

template <class DataType, unsigned short usMaxObjectsNumber>
unsigned short DataChain<DataType, usMaxObjectsNumber>::m_sTypeCounter = 0;

/************************************************************************/
/*																		*/
/*								The Main								*/
/*																		*/
/************************************************************************/

int main(void)
{
    DataChain<double, (unsigned short)5> DoubleChain1(2.4); // Chain of Doubles
    DataChain<double, (unsigned short)5> DoubleChain2(4.9); // Chain of Doubles
    DataChain<int, (unsigned short)4> IntChain1(3);         // Chain of Integers
    DataChain<int, (unsigned short)7> IntChain2(9);         // Chain of Integers

    unsigned short ChoosData;

    /******************************************************************
                            Pay Atention
        DoubleChain1 & DoubleChain2 Use the Same Static Counter.
        IntChain1 & IntChain2 Use Different Static Counters.
    ******************************************************************/

    do
    {
        cout << "Which Type Element yo Want to Add"
             << "\n1 - Int1\t2 - Int2\t3 - Double1\t4 - Double2\tElse - Exit"
             << endl;
        cin >> ChoosData; // Choosing the Chains
                          // Type
        switch (ChoosData)
        {
        case 1: // Linking Integer1
                // Object
            {
                int iValue;

                cout << "Input an Integer: ";
                cin >> iValue;
                IntChain1.NewObject(iValue);
                cout << "\n"
                     << DataChain<int, (unsigned short)4>::m_sTypeCounter
                     << endl; // Printing the Chaims
                              // Lenghth
                break;
            }
        case 2: // Linking Integer2
                // Object
            {
                int iValue;

                cout << "Input an Integer: ";
                cin >> iValue;
                IntChain2.NewObject(iValue);
                cout << "\n"
                     << DataChain<int, (unsigned short)7>::m_sTypeCounter
                     << endl; // Printing the Chaims
                              // Lenghth
                break;
            }
        case 3: // Linking Double1
                // Object
            {
                double dValue;

                cout << "Input a Double: ";
                cin >> dValue;
                DoubleChain1.NewObject(dValue);
                cout << "\n"
                     << DataChain<double, (unsigned short)5>::m_sTypeCounter
                     << endl; // Printing the Chaims
                              // Lenghth

                break;
            }
        case 4: // Linking Double2
                // Object
            {
                double dValue;

                cout << "Input a Double: ";
                cin >> dValue;
                DoubleChain2.NewObject(dValue);
                cout << "\n"
                     << DataChain<double, (unsigned short)5>::m_sTypeCounter
                     << endl; // Printing the Chaims
                              // Lenghth

                break;
            }
        }
    } while (ChoosData > 0 && ChoosData < 5);

    return 0;
}