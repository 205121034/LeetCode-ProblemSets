double A[52];// Using symmetry can half the space need
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured==0) return 0;
        query_glass=min(query_glass, query_row-query_glass);
        int col=min(query_row, query_glass)+2;
        memset(A, 0, col*sizeof(double));
        A[0]=poured;
        for(int i=0; i<query_row; i++){
            // it needs only to consider j<=query_glass 
            int jM=min(i, query_glass);
            for(int j=jM; j>=0; j--){
                double excess=max(0.0, (A[j]-1)/2.0);
                A[j]=excess;
                A[j+1]+=excess;
            }
        }
        return min(1.0, A[query_glass]);
    }
};