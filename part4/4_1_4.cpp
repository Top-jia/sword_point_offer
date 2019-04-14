#include<iostream>

/*

	最长公共子序列: 好比一个数列, 如果分别是两个或多个已知数列的子序列, 且是所有符合此条件序列中最长的, 则称为已知序列的最长公共子序列.
	最长公共子串和最长公共子序列:
		最长公共子串: 子串是串的一个连续的部分, 
		子序列: 则是从不改变序列的顺序, 而从序列去掉任一的元素, 而获取新的序列, 
		比如: acdfg   akdfc
		子串: df
		子序列: adf
	解决动态规划:
		@1:如果问题的最优解所包含的子问题的解也是最优解, 最优解结构
		@2:及某个阶段一旦确定, 就不受这个状态以后决策的影响, 也就是说, 某个状态以后的过程不会影响以前的状态, 至于当前状态有关/
		@3.有子问题直接不独立, 一个子问题在下一个阶段决策种可能被多次使用到, 
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

void LCS(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();
	vector<vector<int>> dp(len1+1, vector<int>(len2 + 1));
	
	for(int j = 0; j <= len2; j++){
		dp[0][j] = 0;
	}

	for(int i = 0; i <= len1; i++){
		dp[i][0] = 0;
	}

	for(int i = 0; i < len1; i++){
		for(int j = 0; j < len2; j++){
			if(str1.at(i) == str2.at(j)){
				dp[i+1][j+1] = dp[i][j] + 1;

			}
			else if(dp[i][j+1] > dp[i + 1][j]){
				dp[i+1][j+1] = dp[i][j+1];
			}
			else{
				dp[i+1][j+1] = dp[i+1][j]
			}

		}
	}
	cout << dp[len1][len2] << endl;
	
	int t1 = 0;
	int t2 = 0;
	while(t1<len1 && t2 < len2){
		if(str1.at(t1) == str2.at(t2)){
			cout << str1.at(t1) << " ";
			t1++;
			t2++;
		}else if(dp[t1+1][t2] == dp[t1][t2+1]){
			t1++;
		}else{
			t2++;
		}
	}
}
