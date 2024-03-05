#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include<string>
using namespace std;
int n, m, h;
int arr[100][100];

bool start() {
	for (int i = 1; i <=n ; i++)
	{
		int x = 1;
		int y = i;
		while (true)
		{
			if (x == h) {
				if (arr[x][y] == 1) {
					y += 1;
				}
				else if (arr[x][y] == 2) {
					y -= 1;
				}
				if (y != i) {
					return false;
				}
				break;
			}
			if (arr[x][y] == 1) {
				x = x + 1;
				y = y + 1;
			}
			else if (arr[x][y] == 2) {
				x = x + 1;
				y = y - 1;
			}
			else {
				x = x + 1;
			}
		}
		
	}
	
	 return true;
}

int main() {
    cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[a][b + 1] = 2;
	}
	
	int ans = -1;
	if (start()) {
		cout << 0;
		return 0;
	}
	
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[i][j] == 0 && arr[i][j + 1] == 0) {
				arr[i][j] = 1;
				arr[i][j + 1] = 2;
				if (start()) {
					if (ans == -1 || ans > 1) {
						ans = 1;
					}
				}
				for (int i2 = 1; i2 <= h; i2++)
				{
					for (int j2 = 1; j2 < n; j2++)
					{
						if (arr[i2][j2] == 0 && arr[i2][j2 + 1] == 0) {
							arr[i2][j2] = 1;
							arr[i2][j2 + 1] = 2;
							if (start()) {
								if (ans == -1 || ans > 2) {
									ans = 2;
								}
								
							}
							for (int i3 = 1; i3 <= h; i3++)
							{
								for (int j3 = 1; j3 < n; j3++)
								{
									if (arr[i3][j3] == 0 && arr[i3][j3 + 1] == 0) {
										arr[i3][j3] = 1;	
										arr[i3][j3 + 1] = 2;
										if (start()) {
											if (ans == -1) {
												ans = 3;
											}
											
											
										}

										arr[i3][j3] = 0;
										arr[i3][j3 + 1] = 0;
									}
								}
							}
							
							arr[i2][j2] = 0;
							arr[i2][j2 + 1] = 0;
						}

					
					}


				}
				arr[i][j] = 0;
				arr[i][j + 1] = 0;
			}
		
		}
	}
	
	cout << ans;
	
	return 0;
}
