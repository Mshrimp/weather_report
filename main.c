#include <stdio.h>
#include "weather.h"

int main(int argc, char *argv[])
{
	get_weather_from_web();

	parse_weather_data();

	show_weather_location();
	show_weather_daily();
	show_weather_update();

	return 0;
}
