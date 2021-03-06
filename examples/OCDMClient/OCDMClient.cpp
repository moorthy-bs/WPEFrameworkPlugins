#include <core/core.h>
#include <ocdm/open_cdm.h>

using namespace WPEFramework;

void TestMethod() {
    OpenCDMAccessor* ocdmSystem = opencdm_create_system();

	if (ocdmSystem != nullptr) {
        if (opencdm_is_type_supported(ocdmSystem, "HelloWorld", "MimeType") == ERROR_NONE) {
            printf("Succeeded\n");
        } else {
            printf("Failed\n");
        }
    }
}

int main()
{
	Core::SystemInfo::SetEnvironment(_T("OPEN_CDM_SERVER"), "127.0.0.1:7912", true);

	printf("Calling test method\n");
	int character;
	do {
		printf(">>");
		character = ::toupper(::getc(stdin));

		switch (character)
		{
		case'T':
		{
			// Time to create a littlebit of NV space for us...

			TestMethod();
			break;
		}
		default: break;
		}
	} while (character != 'Q');

	Core::Singleton::Dispose();

	printf("Done\n");

	return (0);
}

