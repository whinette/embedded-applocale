#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[]) {
	char	*file = "C:\\Windows\\AppPatch\\AppLoc.exe"; // Change this dir for your own applocal path
	char	**args;
	int		i = 1;

	args = (char**)calloc(argc + 2, sizeof(char*) * (argc + 2));
	args[0] = file;
	args[1] = "C:\\Program Files (x86)\\IrfanView\\i_view32_en.exe"; // Change this for the app path
	while (i < argc) {
		args[i + 1] = argv[i];
		++i;
	}
	args[i + 1] = "/L0411"; // See AppLocal documentation to get the locale code you need
	execv(file, args);
	free(args);
	return (0);
}