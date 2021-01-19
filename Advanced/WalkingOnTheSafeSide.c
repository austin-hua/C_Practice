#include <stdio.h>
 
#define MOD 10000
 
int N, M;
 
 
int main(void) {
    while(scanf("%d %d", &N, &M) == 2) {
        int orig[N][M], dp[N][M];
 
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                scanf("%d", &(orig[i][j]));
            }
        }
 
        dp[0][0] = 1;
 
        for(int i = 1; i < N; i++)
            dp[i][0] = orig[i][0] ? 0 : dp[i-1][0];
        for(int j = 1; j < M; j++)
            dp[0][j] = orig[0][j] ? 0 : dp[0][j-1];
        for(int i = 1; i < N; i++) {
            for(int j = 1; j < M; j++) {
                dp[i][j] = orig[i][j] ? 0 : (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
 
        printf("%d\n", (dp[N-1][M-1] % MOD));
 
    }
 
    return 0;
}
