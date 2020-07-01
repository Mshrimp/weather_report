#include <stdio.h>
#include "weather.h"

int main(int argc, char *argv[])
{
	get_weather_from_web();

	parse_weather_data();

	return 0;
}
