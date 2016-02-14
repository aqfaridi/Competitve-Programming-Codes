#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int n,m,k;
int ans[50][50];
char ch[] = {'A','C','G','T'};
string s1[] = {
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT",
        "ATATATATATATATA",
        "TATATATATATATAT"
};

string s2[] = {
        "AGTATGAGTATGAGT",
        "GTATGAGTATGAGTA",
        "TATGAGTATGAGTAG",
        "ATGAGTATGAGTAGT",
        "TGAGTATGAGTAGTA",
        "GAGTATGAGTAGTAT",
        "AGTATGAGTAGTATG",
        "GTATGAGTAGTATGA",
        "TATGAGTAGTATGAG",
        "ATGAGTAGTATGAGT",
        "TGAGTAGTATGAGTA",
        "GAGTAGTATGAGTAT",
        "AGTAGTATGAGTATG",
        "GTAGTATGAGTATGA",
        "TAGTATGAGTATGAG"          
};

string s3[] = {
        "GCATGATCGTCAGCT",
        "TAGCTTCGACTGATC",
        "CCGATGATCATGCTG",
        "AGTCATCGACGTAGT",
        "AGCTGCATGATCGTC",
        "GCTGCATGATCGTCA",
        "CTGCATGATCGTCAG",
        "TGCATGATCGTCAGC",
        "TCGTCAGCTGCATGA",
        "CGTCAGCTGCATGAT",
        "GTCAGCTGCATGATC",
        "TCAGCTGCATGATCG",
        "GATCGTCAGCTGCAT",
        "ATCGTCAGCTGCATG",
        "CAGCTGCATGATCGT"
};

string s4[] = {
        "GCATGATCGTCAGCT",
        "TACGATCGACTGATC",
        "CTGACGATACGTCTG",
        "AGTCATCGACGTAGT",
        "AGCTGCATCTAGGTC",
        "GCTCGATCTCAGTGA",
        "CTGACTTACGCGTAC",
        "TGCATCATGGTCAGC",
        "TCGTCCAGTGACGTA",
        "CGGTACCTGCATGAT",
        "CTGATGCGACTACTG",
        "TCAGCTGACTACTGG",
        "GATCGCTAGTACGCT",
        "ATCGTCCAGTATGCG",
        "CAGCTAGTACCTGGT"
};

string s5[] = {
        "AACCGGTTAACCGGTT",
        "TTGGCCAATTGGCCAA",
        "CCAAGGTTCCGGAATT",
        "AGTCATCGACGTAGT",
        "AGCTGCATCTAGGTC",
        "GCTCGATCTCAGTGA",
        "CTGACTTACGCGTAC",
        "TGCATCATGGTCAGC",
        "TCGTCCAGTGACGTA",
        "CGGTACCTGCATGAT",
        "CTGATGCGACTACTG",
        "GGTTAACCGGTTCCAA",
        "GATCGCTAGTACGCT",
        "AATTCCGGTTAAGGCC",
        "GGTTAACCGGAACCTT"
};

string s6[] = {
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA",
        "AAAATTTTAAAATTT",
        "TTTTAAAATTTTAAA"
};

string s7[] = {
        "AAAGGGCCCTTTAAA",
        "TTTGGGCCCAAATTT",
            "CCCAAAGGGTTTCCC",
        "GGGCCCAAATTTGGG",
            "AAATTTGGGCCCAAA",
        "CCCGGGTTTAAACCC",
        "TTTCCCAAAGGGTTT",
        "GGGTTTAAACCCGGG",
        "CCCTTTGGGAAACCC",
        "AAAGGGCCCTTTAAA",
        "TTTGGGCCCAAATTT",
        "CCCAAAGGGTTTCCC",
        "GGGCCCAAATTTGGG",
        "AAATTTGGGCCCAAA",
        "CCCGGGTTTAAACCC",
        "TTTCCCAAAGGGTTT",
        "GGGTTTAAACCCGGG",
        "CCCTTTGGGAAACCC"

};
void generate()
{
    string str;

    do{
         str += ch[0];
         str += ch[1];
         str += ch[2];
         str += ch[3];
         //cout<<ch[0]<<ch[1]<<ch[2]<<ch[3]<<endl;
    }while(next_permutation(ch,ch+4));

}
int main()
{
    generate();

    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        
        if(k <= n*m)
        {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<"A";
                cout<<endl;
            }
            continue;
        }
       
       if(k <= 2*n*m)
       {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<s6[i][j];
                cout<<endl;
            }
            continue;
       
       }

       if(k <= 3*n*m)
       {      
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<s1[i][j];
                cout<<endl;
            }
            continue;
       }
        
       if(k <= 5*n*m)
       {
       
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<s7[i][j];
                cout<<endl;
            }
            continue;
       }
        
       if(k <= m*n*m)
       {    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<s2[i][j];
                cout<<endl;
            }
            continue;
       }


       if(k <= 3*m*n*m)
       {
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<s3[i][j];
                cout<<endl;
            }
            continue;
       
       }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<s4[i][j];
            cout<<endl;
        }

    }
    return 0; 
}
