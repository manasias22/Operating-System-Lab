// Banker&#39;s Algorithm  
#include &lt;stdio.h&gt;  
int main()  
{  
    // P0, P1, P2, P3, P4 are the Process names here  
  
    int n, m, i, j, k;  
    n = 5;                         // Number of processes  
    m = 3;                         // Number of resources  
    int alloc[5][3] = {{0, 1, 0},  // P0 // Allocation Matrix  
                       {2, 0, 0},  // P1  
                       {3, 0, 2},  // P2  
                       {2, 1, 1},  // P3  
                       {0, 0, 2}}; // P4  
  
    int max[5][3] = {{7, 5, 3},  // P0 // MAX Matrix  
                     {3, 2, 2},  // P1  
                     {9, 0, 2},  // P2  
                     {2, 2, 2},  // P3  
                     {4, 3, 3}}; // P4  
  
    int avail[3] = {3, 3, 2}; // Available Resources  
  
    int f[n], ans[n], ind = 0;  
    for (k = 0; k &lt; n; k++)  
    {  
        f[k] = 0;  
    }  
    int need[n][m];  
    for (i = 0; i &lt; n; i++)  
    {  
        for (j = 0; j &lt; m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  

    int y = 0;  
    for (k = 0; k &lt; 5; k++)  
    {  
        for (i = 0; i &lt; n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j &lt; m; j++)  
                {  
                    if (need[i][j] &gt; avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y &lt; m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i &lt; n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf(&quot;The following system is not safe&quot;);  
            break;  

        }  
    }  
    if (flag == 1)  
    {  
        printf(&quot;Following is the SAFE Sequence\n&quot;);  
        for (i = 0; i &lt; n - 1; i++)  
            printf(&quot; P%d -&gt;&quot;, ans[i]);  
        printf(&quot; P%d&quot;, ans[n - 1]);  
    }  
    return (0);  
}
