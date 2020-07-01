#ifndef __WEATHER_H__
#define __WEATHER_H__

typedef struct {
	char id[32];
	char name[32];
	char country[32];
	char path[32];
	char timezone[32];
	char timezone_offset[32];
} location_t;

typedef struct {
	char date[32];
	char text_day[32];
	char code_day[32];
	char text_night[32];
	char code_night[32];
	char high[32];
	char low[32];
	char rainfall[32];
	char precip[32];
	char wind_direction[32];
	char wind_direction_degree[32];
	char wind_speed[32];
	char wind_scale[32];
	char humidity[32];
} weather_day_t;

typedef struct {
	location_t location;
	weather_day_t daily[3];
	char last_update[32];
} weather_t;


int get_weather_from_web(void);
int parse_weather_data(void);

int show_weather_location(void);
int show_weather_daily(void);
int show_weather_update(void);



#endif /* __WEATHER_H__ */

