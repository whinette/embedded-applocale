#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[]) {
	char	*file = "C:\\Windows\\AppPatch\\AppLoc.exe"; // Change this dir for your own applocal path
	char	*app = "C:\\Program Files (x86)\\IrfanView\\i_view32_en.exe"; // Change this for the app path
	char	*locale = "/L0411"; // See AppLocal documentation to get the locale code you need
	char	**args;
	int		i = 1, len = 0;

	if ((args = (char**)calloc(4, sizeof(char*) * 4)) == NULL) {
		return (-1);
	}
	args[0] = file;
	args[1] = app;
	args[3] = locale;
	while (i < argc) {
		len = len + strlen(argv[i]);
		++i;
	}
	if ((args[2] = (char*)calloc(len + 1 + i * 3, sizeof(char) * (len + 1 + i * 3))) == NULL) {
		free(args);
		return (-1);
	}
	i = 1;
	while (i < argc) {
		args[2] = strcat(args[2], argv[i]);
		args[2] = strcat(args[2], " ");
		++i;
	}
	execv(file, args);
	free(args[2]);
	free(args);
	return (0);
}
