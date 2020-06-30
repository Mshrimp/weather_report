#ifndef __WEATHER_H__
#define __WEATHER_H__

typedef struct {
	char id[32];
	char name[32];
	char country[32];
	char path[32];
	char timezone[32];
	char timezone_offset[32];
	/*
	char text[32];
	char code[32];
	char temperature[32];
	char update_time[32];
	*/
} location_t;


typedef struct {
	char date[32];
	char text_day[32];
	char code_day[32];
	char text_night[32];
	char code_night[32];
	char high[4];
	char low[4];
	char rainfall[8];
	char precip[32];
	char wind_direction[32];
	char wind_direction_degree[16];
	char wind_speed[8];
	char wind_scale[4];
	char humidity[4];
} weather_day_t;

typedef struct {
	location_t location;
	weather_day_t daily[3];
	char last_update[32];
} weather_t;


#endif /* __WEATHER_H__ */

