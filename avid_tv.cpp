    #include <iostream>  
    #include<stdlib.h>
    using namespace std;  
      
    class prog  
    {  
    public:  
    int id;             //unique id to identify a program  
    int cnt;            //This will tell me what max_time, I can spend on  
                      //tv till end of this program, if I include this program.  
    int start;          // Start time of the program  
    int end;            // End time of the program  
    int channel_no;     // Channel id of the program  
      
    prog(char i, int count, int st, int en)  
    {  
      id = i;  
      cnt = count;  
      start = st;  
      end = en;  
    }  
    };  
      
    int comp(const void *a,const void *b)  
    {  
    if ((*(prog *)a).end == (*(prog *)b).end)  
    return 0;  
    else  
    if ((*(prog *)a).end < (*(prog *)b).end)  
            return -1;  
     else  
        return 1;  
    }  
      
    /* Test Data 
    Program id P1    P2    P3 
    Start time 8:00    9:00    10:30 
    End time 8:30    10:00 11:30 
     
    Channel 2: 
    Program id P4    P5    P6 
    Start time 8:15    9:30    10:45 
    End time 9:15    10:15 11:30 
    */  
      
    int rf4rr4(int argc, char* argv[])  
    {  
    /* say it's the final unsorted array after merging. 
    I will sort it using qsort. We should do a sorted 
    merge from individual k channel arrays that will take 
    O(nlogk) time where n is total number of programs.*/  
    prog programs[6]={  
     prog(1,0,800,850),  
     prog(2,0,900,1000),  
     prog(3,0,1050,1150),  
     prog(4,0,825,925),  
     prog(5,0,950,1025),  
     prog(6,0,1075,1150)  
    };  
    int i, max, j, n;  
      
    // Printing Just for Debuging  
    for (i=0;i<6;i++)  
     cout << programs[i].id << " ";  
      
    /*Sort the array. We should do a sorted merge from individual 
    k channel-arrays that will take O(nlogk) time where n is 
    total number of programs. */  
    qsort(programs, 6, sizeof(prog), comp) ;
      
    // Printing Just for Debuging  
    for (i=0;i<6;i++)  
    cout << programs[i].id << " ";  
      
    n = sizeof(programs)/sizeof(prog);  
      
    for (i=0; i< n; i++)  
    {  
    max = 0;  
    j = 0;  
    while (programs[i].start > programs[j].end )  
    {  
        if (max < programs[j].cnt)  
        {  
            max = programs[j].cnt;  
        }  
        j++;      
    }  
    programs[i].cnt = max + programs[i].end - programs[i].start;  
    }  
      
    //Get the maximum count value  
    int res = 0;  
    for (i=0; i< n; i++)  
    {  
    if (res < programs[i].cnt)  
        res = programs[i].cnt;      
    }  
      
    cout << "result =" << res << endl;  
    return 0;  
    }  
