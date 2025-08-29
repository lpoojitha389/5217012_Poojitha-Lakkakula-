#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int x, y, dist;
} Point;

int n;
char grid[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == '.' && !visited[x][y];
}

int minimumMoves(int startX, int startY, int goalX, int goalY) {
    Point queue[MAX * MAX];
    int front = 0, rear = 0;

    memset(visited, 0, sizeof(visited));

    queue[rear++] = (Point){startX, startY, 0};
    visited[startX][startY] = 1;

    while (front < rear) {
        Point curr = queue[front++];
        if (curr.x == goalX && curr.y == goalY)
            return curr.dist;
        for (int d = 0; d < 4; d++) {
            int nx = curr.x;
            int ny = curr.y;

            while (1) {
                nx += dx[d];
                ny += dy[d];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 'X')
                    break;

                if (!visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    queue[rear++] = (Point){nx, ny, curr.dist + 1};
                }
            }
        }
    }

    return -1; 
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", grid[i]);

    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int result = minimumMoves(startX, startY, goalX, goalY);
    printf("%d\n", result);

    return 0;
}
