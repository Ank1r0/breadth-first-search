#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <queue>


//using namespace std;

template <typename T>
class queue
{
	struct que
	{
		T data;
		que* next = nullptr;
		que* prev = nullptr;

		que() {}

		que(T data, que* next = nullptr, que* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	size_t size = 0;

	que* root = nullptr;
	que* head = nullptr;

public:
	void enqueue(T _data)
	{
		if (root != nullptr)
		{
			root = new que(_data, root);
			root->next->prev = root;
			++size;
		}
		else
		{
			head = root = new que(_data);
			++size;
		}
	}

	T dequeue()
	{
		if (size > 0)
		{
			que* temp = head;
			T t = temp->data;//
			if (size == 1)
			{
				root = nullptr;
				head = nullptr;
			}
			else
			{
				head = head->prev;
				head->next = nullptr;//<-ERROR 
			}
			--size;
			delete temp;
			return t;
		}
		throw exception();
	}

	bool check_queue()
	{
		if (size > 0)
		{
			return 1;
		}
		return 1;
	}

	int get_size()
	{
		return size;
	}


	bool find(T _data)
	{
		que* temp = root;
		if (size > 0)
		{
			while (temp != nullptr)
			{
				if (temp->data == _data)
				{
					return true;
				}
				temp = temp->next;
			}
		}

		return false;
	}
};


void main()
{
	int const n = 6, m = 7;
	char map[n][m];
	//char checked[n][m] = { 0 };
	queue<std::pair<int, int>> islands;
	int count = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			scanf("%c", map[i] + j);
			getc(stdin);
		}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}

	std::pair<int, int> part;

	for (int k = 0; k < n; ++k)
	{
		for (int l = 0; l < m; ++l)
		{
			if (map[k][l] == '1')
			{
				count = 0;
				islands.enqueue({ k,l });

				map[k][l] = '2';
				int i, j;

				while (islands.get_size())
				{
					//printf("\nsize - %d", islands.get_size());
					part = islands.dequeue();
					++count;
					i = part.first, j = part.second;
					//printf("\n i %d, j %d, ", start.first, start.second);

					if (i > 0)
					{
						if (map[i - 1][j] == '1')
						{
							islands.enqueue({ i - 1, j });
							map[i - 1][j] = '2';
						}
					}
					if (i < n - 1)
					{
						if (map[i + 1][j] == '1')
						{
							islands.enqueue({ i + 1, j });
							map[i + 1][j] = '2';
						}
					}
					if (j > 0)
					{
						if (map[i][j - 1] == '1')
						{
							islands.enqueue({ i, j - 1 });
							map[i][j - 1] = '2';
						}
					}
					if (j < m - 1)
					{
						if (map[i][j + 1] == '1')
						{
							islands.enqueue({ i, j + 1 });
							map[i][j + 1] = '2';

						}
					}
				}//WHILE
				printf("%d\n", count);
			}//IF MAP[K][L] == 1
		}//L-CYCLE
	}//K-CYCLE

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}

	//printf("islands - %d\n", count);

	system("pause");
}