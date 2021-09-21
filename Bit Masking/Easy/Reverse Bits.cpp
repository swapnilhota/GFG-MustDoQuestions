/*
Given a non-negative integer n. Reverse the bits of n and print the number obtained after reversing the bits.
Note:  The actual binary representation of the number is being considered for reversing the bits, no leading 0’s are being considered.
 
Example 1:
Input : 
N = 11
Output:
13
Explanation:
(11)10 = (1011)2.
After reversing the bits we get:
(1101)2 = (13)10.
Example 2:

Input : 
N = 10
Output:
5
Explanation:
(10)10 = (1010)2.
After reversing the bits we get:
(0101)2 = (101)2
        = (5)10.
Your task:
You don't need to read input or print anything. Your task is to complete the function reverseBits() which takes an integer N as input and returns the number obtained after reversing bits.
 
Expected Time Complexity : O(number of bits in the binary representation of N)
Expected Auxiliary Space :  O(1)
 
Constraints :
1 ≤ N ≤ 109
*/

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        int i=0;
        while((1<<i)<=n)
        {
            i++;
        }
        
        i--;
        
        for(int x=0; x<=i/2; x++)
        {
            int b1 = (1<<x)&n;
            int b2 = (1<<(i-x))&n;
            if(b1!=0 && b2==0)
            {
                n = n^(1<<x);
                n = n|(1<<(i-x));
            }
            else if(b1==0 && b2!=0)
            {
                n = n|(1<<x);
                n = n^(1<<(i-x));
            }
        }
        
        return n;
    }
};
