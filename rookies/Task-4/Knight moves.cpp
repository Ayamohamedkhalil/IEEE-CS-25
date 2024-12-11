#include <array>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

//By Searching

inline bool isValidMove(const std::vector<std::vector<int>>& board, int i, int j)
{
    if (i < 0 || i >= static_cast<int>(board.size()))
        return false;
    else if (j < 0 || j >= static_cast<int>(board[i].size()))
        return false;
    else if (board[i][j] != -1)
        return false;
    else
        return true;
}

int solve(std::vector<std::vector<int>>& board,
          const std::pair<int,int>& source,
          const std::pair<int,int>& dest)
{
    static const std::array<std::pair<int,int>, 8> moves {{{2 , 1}, {1 , 2},
                                                                    {-1, 2}, {-2, 1},
                                                                    {-2,-1}, {-1,-2},
                                                                    {1 ,-2}, {2 ,-1}}};

    std::queue<std::pair<int,int>> q;
    int next_i, next_j;


    board[source.first][source.second] = 0;
    q.push(source);


    while (!q.empty() && board[dest.first][dest.second] == -1)
    {
        auto curr = q.front();
        q.pop();

        for (const auto& mv: moves)
        {
            next_i = curr.first + mv.first;
            next_j = curr.second + mv.second;

            if (isValidMove(board, next_i, next_j))
            {
                board[next_i][next_j] = board[curr.first][curr.second] + 1;
                q.emplace(next_i, next_j);
            }
        }
    }

    return board[dest.first][dest.second];
}

int main()
{
    int tests;
    std::cin >> tests;

    while (tests--)
    {
        char a, b, c, d;
        std::cin >> a >> b >> c >> d;

        std::vector<std::vector<int>> board (8, std::vector<int>(8, -1));

auto source = std::pair<int,int>{b - '0' - 1, a - 'a'};
    auto     dest   = std::pair<int,int>{d - '0' - 1, c - 'a'};

        std::cout << solve(board, source, dest) << std::endl;
    }

    return 0;
}
