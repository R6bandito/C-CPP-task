/*
		C ++ tasks
*/

#include "scope loop.h"
#include "lambda.h"

static void task2_example() { scope_loop(); scope_loop2();scope_loop3(); }	//scope-based for loop
static void task2_main() { task_scope_loop_main(); }

static void task3_lambda_func() { task_lambda_main(); }

int main() {
	//task2_main();
	task3_lambda_func();

	return 0;
}