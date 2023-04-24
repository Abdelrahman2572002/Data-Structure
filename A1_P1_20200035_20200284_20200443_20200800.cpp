// =============================================================
// Student: Ahmed Salman Fahmin
// StudentID: 20200035
// =============================================================
// Student: Abdelrahamn Ramdan AboElela
// StudentID: 20200284
// =============================================================
// Student: Mohamed Refaat Mohamed
// StudentID: 20200443
// =============================================================
// Student: Adel Tarek Mouneer
// StudentID: 20200800
// =============================================================



#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

class BigInt
{   
    private:
        string number = "0";
        bool neg = 0;
    public:
        BigInt(string decStr)
        {
            number = "";

            int n = decStr.length();
            int beg = 0;
            if(decStr[0] == '-')
            {
                neg = 1;
                beg = 1;
            }
            for(int i = n-1; i >= beg; i--)
            {
                if(!isdigit(decStr[i]))
                {
                    try
                    {

                        // throw("Invalid Input"); 
                    }catch (...)
                    {
                        cout << "Invalid Input" << endl;
                        decStr ="0";
                        neg = 0;
                        break;
                    }
                                   
                }

            }
            number = decStr;

        }
        BigInt(int num)
        {
            number = to_string(num);
            if(number[0] == '-')
                neg=1;
        }
        string sumNum(string num1, string num2)
        {

            string result = "";
            int currLen = num1.length();
            int anotherLen = num2.length();
            int carry =0, tempSum, differnce;

            // Compare operands' lengths
            if(currLen > anotherLen)
                {
                    swap(num1, num2);
                    swap(currLen, anotherLen);
                }
                    
                differnce = anotherLen-currLen;

                //Loops from the end of both strings
                for (int i = currLen -1; i >= 0; i--)
                {
                    tempSum = ((num1[i] - '0') + (num2[i + differnce] - '0') + carry);
                    carry = tempSum /10;
                    result += tempSum % 10 + '0';
                }
                //Loops on the padding part
                for(int i = differnce-1; i >=0; i--)
                {
                    tempSum = ((num2[i] - '0') + carry);
                    carry = tempSum /10;
                    result += tempSum % 10 + '0';

                }
                // Checks and Adds the carry if found
                if (carry)
                    result += carry + '0';
                // Reverse the result string to display it correctly

                reverse(result.begin(), result.end());
                return result;    
        }
        string subNum(string num1, string num2)
        {
            string num3;
            // If second string is larger
            if (num1.length() < num2.length())
                swap(num1, num2);
        
            // Calculate The Length of the Two operands
            int currLen =num1.length();
            int anotherLen =num2.length();
        
            // If they are equal in length
            int diffLen = currLen - anotherLen;
        
            // Padding operands theat ar not equal
            for (int i = 0; i < diffLen; i++)
               num2 = "0" +num2;
        
            // Subtracts by Complementing
            num3 = sumNum(num1, compelment(num2));
        
            // Checks and handles carry underflow
            if (num3.length() >num1.length())
            {
                string::iterator it;
        
                char carryFlag = num3[0];
                string bit = { carryFlag };
                it = num3.begin();
                num3.erase(it);
                num3 = sumNum(num3, bit);
                return num3;
            }
            else 
                return compelment(num3);
        }
        BigInt operator+(BigInt anotherDec)
        {
            // Checks if both are positive
            if(!(neg || anotherDec.getNegative()))
            {   
                
                return BigInt(sumNum(number, anotherDec.number));
            }

            // Checks if only one is negative
            if (neg || anotherDec.getNegative())
            {
                string tempNum1, tempNum2 = "" ;
            // Checks if the first one is negative and the second is positive
                if(neg && !anotherDec.getNegative())
                {
                    tempNum1 = number.substr(1,number.length());
                    return BigInt(subNum(anotherDec.number, tempNum1));
                }
            
            // Checks if the first one is positive and the second is negative
                else if(!neg && anotherDec.getNegative())
                {
                    tempNum1 = anotherDec.number.substr(1,anotherDec.number.length());
                    return BigInt(subNum(number,tempNum1));

                }
            // Checks if both are negative
                else
                {
                    tempNum1 = anotherDec.number.substr(1,anotherDec.number.length());
                    tempNum2 = number.substr(1,number.length());
                    string negNum= "-";
                    return BigInt(negNum.append(sumNum( tempNum1, tempNum2)));
                }
                
            }
            // Random return that will never happen to avoid warning
            return BigInt("0");
        }
        BigInt operator-(BigInt anotherDec)
        {
            cout << "hello world";
            // Checks if both are positive
            if(!(neg || anotherDec.getNegative()))
            {   
                
                return BigInt(subNum(number, anotherDec.number));
            }

            // Checks if only one is negative
            if (neg || anotherDec.getNegative())
            {
                string tempNum1, tempNum2 = "" ;
                string negNum="-";
            // Checks if the first one is negative and the second is positive
                if(neg && !anotherDec.getNegative())
                {
                    tempNum1 = number.substr(1,number.length());
                    return BigInt(negNum.append(sumNum( tempNum1, anotherDec.number)));
                }
            
            // Checks if the first one is positive and the second is negative
                else if(!neg && anotherDec.getNegative())
                {
                    tempNum1 = anotherDec.number.substr(1,anotherDec.number.length());
                    return BigInt(sumNum(number,tempNum1));

                }
            // Checks if both are negative
                else
                {
                    tempNum1 = anotherDec.number.substr(1,anotherDec.number.length());
                    tempNum2 = number.substr(1,number.length());
                    return BigInt(subNum(tempNum2, tempNum1));
                }
                
                

            }
            // Random return that will never happen to avoid warning
            return BigInt("1337");
        }
        int bigIntSize()
        {
            return number.size();
        }
        friend ostream& operator<<(ostream& out, BigInt num)
        {
            out << num.number ;
            return out;
        }
        string getNumber()
        {
            return number;
        }
        void setNumber(string num)
        {
            int n = num.size();
            int beg = 0;
            if(num[0] == '-')
            {
                neg = 1;
                beg = 1;
            }
            for(int i = n-1; i >= beg; i--)
            {
                
                try
                {

                    if(!isdigit(num[i]))
                        throw("Invalid Input"); 
                }catch (...)
                {
                    cout << "Invalid Input" << endl;
                    num ="0";
                    neg = 0;
                    break;
                }
                                   
                

            }
            number = num;

        }
        string compelment(string num)
        {
            // Stores the complement
            string complement = "";
        
            for (int i = 0; i < num.size(); i++) {
        
                // subtract every number from 9
                complement.push_back('9' - num[i] + '0');
            }
        
            // Return the result
            return complement;
        }
        bool getNegative()
        {
            return neg;
        }
        
};
int main()
{

//Test case1
        BigInt x1("123456789012345678901234567890");
        BigInt y1("113456789011345678901134567890");

        BigInt num1 = x1 + y1;

        cout << "123456789012345678901234567890 + 113456789011345678901134567890 = ";
        cout << num1 << "\n\n";

        //Test case2
        BigInt x2("123456789012345678901234567890");
        BigInt y2("1134567890");

        cout << "123456789012345678901234567890 + 11345678901134567890113456789 = ";
        cout << x2 + y2 << "\n\n";

        //Test case3
        BigInt x3("99999999999999");
        BigInt y3("999999999999999");
        
        cout << "99999999999999 + 99999999999999 = ";
        cout << x3 + y3 << "\n\n";

        //Test case4
        BigInt x4("-99999999999999");
        BigInt y4("-99999999999999");

        BigInt num2 = x4 + y4;
        cout << "-99999999999999 + -99999999999999 = ";
        cout << num2 << "\n\n";

        //Test case5
        BigInt x5(5);
        BigInt y5(-5);

        cout << "5 - 5 = ";
        cout << x5 + y5 << "\n\n";

        //test case6
        BigInt x6(9999999);
        BigInt y6(-99999);
        cout << "9999999 - 99999 = ";
        cout << x6 + y6 << "\n\n";


    return 0;    
}