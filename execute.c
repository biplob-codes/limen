#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
void execute(char *commands[], int *last_status)
{
	if (strcmp(commands[0], "cd") == 0) {
		char *dir = commands[1] ? commands[1] : getenv("HOME");
		if (dir == NULL) {
			dir = "/";
		}
		if (chdir(dir) != 0)

		{
			perror("cd");
			return;
		}
		return;
	} else if (strcmp(commands[0], "exit") == 0) {
		exit(0);
	} else {
		struct sigaction ign = {.sa_handler = SIG_IGN};
		sigemptyset(&ign.sa_mask);
		struct sigaction old;
		sigaction(SIGINT, &ign, &old);

		pid_t pid = fork();
		if (pid < 0) {
			perror("fork failed");
			exit(1);
		}
		if (pid == 0) {
			char buf[32];
			sigaction(SIGINT, &old, NULL);
			for (int i = 1; commands[i] != NULL; i++) {
				if (strcmp(commands[i], "$?") == 0) {
					int result =
					    snprintf(buf, sizeof(buf), "%d",
						     *last_status);
					if (result < 0 ||
					    result >= (int)sizeof(buf)) {
						perror(
						    "converstion to string "
						    "failed for last status");
						exit(1);
					}
					commands[i] = buf;
				}
			}

			execvp(commands[0], commands);
			perror("execv failed");
			exit(127);
		} else {

			int status;
			pid_t waited = waitpid(pid, &status, 0);
			if (waited < 0) {
				perror("waitpid");
				exit(1);
			}
			if (WIFEXITED(status)) {
				*last_status = WEXITSTATUS(status);

			} else if (WIFSIGNALED(status)) {
				*last_status = WTERMSIG(status) + 128;
			}
			sigaction(SIGINT, &old, NULL);
		}
	}
}