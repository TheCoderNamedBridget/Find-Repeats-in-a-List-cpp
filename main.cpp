
/*
Bridget Naylor
Date: 10/11/2020
Exam 1 Part 2
*/
#include <iostream>
using namespace std;

int findKeyRepeats( int size, int list[], int key )
{
    if ( size == 0 || (size == 1 && list [0] != key) )
    {
        return 0;
    }
    bool keyFound = false;
    int start = 0;
    int end = size;
    int middle = (start + end)/2;
    int keyFoundFirstAt = -1;
    bool searchRight = true;
    bool searchLeft = true;
    while ( !keyFound )
    {
        if ( list[middle] == key )//key exists in list
        {
            keyFoundFirstAt = middle;
            keyFound = true;
            if ( middle == size -1 || list[middle + 1] != key )
            {
                searchRight = false;
            }
            if ( middle == 0 || list[middle - 1] != key )
            {
                searchLeft = false;
            }
            if ( !searchLeft && !searchRight)
            {
                return 1;
            }
            //cout<<"searchRight "<<searchRight<<" searchLeft "<<searchLeft<<endl;
        }
        else if (  middle == end || middle == start )//key not in list
        {
            keyFound = true;
            return keyFoundFirstAt;
        }
        else if ( list[middle] > key )
        {
            end = middle;
            middle = (middle + start) / 2;
        }
        else if ( list[middle] < key )
        {
            start = middle;
            middle += (end - middle)/2;
        }
        
    }
    //cout<<"here"<<endl;
    //start of finding how many of the key exist
    bool repeatF = false;
    int s1 = 0;
    int e1 = keyFoundFirstAt;
    int m1 = (s1 + e1) / 2;
    
    int s2 = keyFoundFirstAt;
    int e2 = size;
    int m2 = (s2 + e2)/2;
    // cout<<"s1 "<<s1<<endl;
    // cout<<"s2 "<<s2<<endl;
    // cout<<"m1 "<<m1<<endl;
    //cout<<"m2 "<<m2<<endl;
    if ( !searchLeft )
    {
        m1 = e1;
    }
    if ( !searchRight )
    {
        m2 = s2;
    }
    //cout<<"keyfoundfirst at "<<keyFoundFirstAt<<endl;
    
    //cout<<"m2 != size - 1 "<<(m2 != size - 1 )<<endl;
    //cout<<"list[m2 + 1] == key "<<(list[m2 + 1] == key)<<endl;
    while ( !repeatF )
    {
        //cout<<"big "<<( !searchLeft && !searchRight && (m1 != 0 && list[m1 - 1] != key) && (m2 + 1 <= size -1 && list[m2 + 1] != key ))<<endl;
        // cout<<"big1 "<<( !searchRight )<<endl;
        // cout<<"big2 "<<( !searchLeft && !searchRight && (m1 != 0 && list[m1 - 1] != key) && (m2 + 1 <= size -1 && list[m2 + 1] != key ))<<endl;
        if ( !searchLeft && !searchRight && ((m1 == 0 && list[m1] == key) || (m1 - 1 >= 0 && list[m1 - 1] != key))&& ((m2 + 1 <= size -1 && list[m2 + 1] != key ) || (m2 <= size -1 && list[m2] == key )))
        {
            //cout<<"m2 "<<m2<<" m1 "<<m1<<endl;
            //cout<<"m2 "<<m2<<" m1 "<<m1<<endl;
            return (m2 - m1) +1;
        }
        else if ( searchRight && ((m2 + 1 <= size - 1 && list[m2 + 1] == key) || (m2 == size -1 && list[m2] == key)))
        {
            s2 = m2;
            m2 += (e2 - m2)/2;
            //cout<<"2. m2 "<<m2<<endl;
            //cout<<"2. size - 1 "<<size - 1<<endl;
            if ( m2 == size -1 )
            {
                cout<<"FALSE"<<endl;
                searchRight = false;
            }
        }
        else if ( searchRight && m2 + 1 <= size - 1 && list[m2 + 1] != key)
        {
            e2 = m2;
            m2 -= (m2 - s2)/2;
            //cout<<"3. s2 "<<s2<<endl;
            //cout<<"3. m2 "<<m2<<endl;
            if ( list[m2 + 1] != key && list[m2] == key)
            {
                searchRight = false;
            }
        }
        else if ( searchLeft && ((m1 - 1 >= 0 && list[m1 - 1] == key) ||(m1 == 0 && list[m1] == key)) )
        {
            e1 = m1;
            m1 = (m1 + s1)/2;
            //cout<<"3. m1 "<<m1<<endl;
            if ( m1 == 0 )
            {
                //cout<<"FALSE"<<endl;
                searchLeft = false;
            }
        }
        else if ( searchLeft && m1  - 1 >= 0 && list[m1 - 1] != key )
        {
            s1 = m1;
            m1 += (e1 - m1)/2;
            //cout<<"3b. m1 "<<m1<<endl;
            if ( list[m1 - 1] != key && list[m1] == key )
            {
                //cout<<"FALSE"<<endl;
                searchLeft = false;
            }
        }
        
    }
    
    //cout<<"Key Found at "<<keyFoundFirstAt<<endl;
    
}

int main()
{
    cout<<"Enter size of list "<<endl;
    int n;
    cin>>n;
    if (n != 0)
    {
        
    
        srand (time(0));
        int listOfNums[n] = {0};
        int key = rand() % n;
        int numRepeats = (rand() % n)/3;
        //cout<<"numRepeats "<<numRepeats<<endl;
        int numToRepeat = 0;
        for ( int i = 0; i < n ; i++ )
        {
            
            if ( numRepeats != 0 )
            {
                
                listOfNums[i] = numToRepeat;
                numRepeats -= 1;
            }
            else
            {
                numToRepeat = i;
                numRepeats = (rand() % n)/3;
                //cout<<"numToRepeat "<<i<<endl;
                //cout<<"numRepeats "<<numRepeats<<endl;
                listOfNums[i] = numToRepeat;
            }
            
            cout<<"i "<<i<<" Value at i "<<listOfNums[i]<<endl;
        }
        cout<<"KEY "<<key<<" found "<<findKeyRepeats( n, listOfNums, key )<<" times";
    }
    else
    {
        cout<<"invalid size "<<endl;
    }
    
    
    //Testing Valeus
    // int listy[9] = {0, 0, 2, 10, 10, 10, 10, 10, 15};//5times
    // cout<<"KEY "<<10<<" found "<<findKeyRepeats( 9, listy, 10 )<<" times";
    
    // int listy1[9] = {0, 0, 0, 0, 0, 0, 0, 10, 10};//2 times
    // cout<<"KEY "<<10<<" found "<<findKeyRepeats( 9, listy1, 10 )<<" times";
    
    // int listy3[9] = {10, 10, 10, 11, 11, 11, 11, 11, 12};//3times
    // cout<<"KEY "<<10<<" found "<<findKeyRepeats( 9, listy3, 10 )<<" times";
    
    // int listy4[9] = {10, 10, 10, 10, 11, 11, 11, 11, 12};//4times
    // cout<<"KEY "<<10<<" found "<<findKeyRepeats( 9, listy4, 10 )<<" times";
    
    // int listy5[9] = {11, 11, 11, 11, 11, 12, 12, 12, 12};//4times
    // cout<<"KEY "<<12<<" found "<<findKeyRepeats( 9, listy5, 12 )<<" times";
}


