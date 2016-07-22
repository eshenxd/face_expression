#include <main_task.h>

using namespace std;

int main(int argc , char* argv[])
{
	if (argc != 2)
	{
		cout << "parameter not enough.." << endl;
		return 1;
	}

	Main task;
	task.run_task(argv[1]);

	return0;
		
}