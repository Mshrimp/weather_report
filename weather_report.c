#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "cJSON.h"
#include "weather.h"

#define WEATHER_IP_ADDR	"116.62.81.138"
#define WEATHER_PORT	80
#define PRIVATE_KEY "SBx4_FIjI6Y5CDu4V"
#define GET_REQUEST_PACKAGE_FMT	"GET https://api.seniverse.com/v3/weather/%s.json?key=%s&location=%s&language=zh-Hans&unit=c\r\n\r\n"

#define NOW	"now"
#define DAILY	"daily"
#define LOCATION	"shenzhen"

char package[256] = { 0 };
char data[1024] = { 0 };

weather_t weather;

int get_request_package(void)
{
	memset(package, 0, 256);
	sprintf(package, GET_REQUEST_PACKAGE_FMT, DAILY, PRIVATE_KEY, LOCATION);

	printf("%s, package: %s\n", __func__, package);

	return 0;
}

int get_weather_from_web(void)
{
	int clnt_fd = -1;
	struct sockaddr_in serv_addr;
	int read_cnt = 0;
	int count = 0;
	int ret = -1;

	get_request_package();
	printf("len: %ld\n", strlen(package));

	clnt_fd = socket(PF_INET, SOCK_STREAM, 0);
	if (-1 == clnt_fd) {
		perror("socket failed!\n");
		return -1;
	}
	printf("clnt_fd: %d\n", clnt_fd);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(WEATHER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(WEATHER_IP_ADDR);
	bzero(&(serv_addr.sin_zero), 8);

	printf("serv_addr, port: 0x%x, ip: 0x%x\n", serv_addr.sin_port, serv_addr.sin_addr.s_addr);

	ret = connect(clnt_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr));
	if (-1 == ret) {
		perror("connect failed!\n");
		return ret;
	}

	printf("connect success!\n");

	//memset(package, 0, 256);
	//sprintf(package, GET_REQUEST_PACKAGE_FMT, TIME, PRIVATE_KEY, LOCATION);
	//printf("%s, package: %s\n", __func__, package);
	//printf("len: %ld\n", strlen(package));

	ret = send(clnt_fd, package, strlen(package), 0);
	printf("send ret: %d\n", ret);

	memset(data, 0, 1024);
	read_cnt = recv(clnt_fd, (void *)data, sizeof(data), 0);
	/*
	while (read_cnt == 0) {
		count++;
		read_cnt = recv(clnt_fd, (void *)data, sizeof(data), 0);
		if (errno != 0)
			printf("recv error: %d, %s, count: %d\n", errno, strerror(errno), count);
	}*/
	printf("recv, read_cnt: %d\n", read_cnt);

	printf("recv: %s\n", data);

	close(clnt_fd);

	return 0;
}

int show_weather(void)
{
	printf("");

	return 0;
}

int parse_weather_location(cJSON *cJSON_location, location_t *location)
{
	cJSON *json = NULL;
	printf("%s, %s\n", __func__, cJSON_Print(cJSON_location));

	json = cJSON_GetObjectItem(cJSON_location, "id");
	strncpy(location->id, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, location->id);

	json = cJSON_GetObjectItem(cJSON_location, "name");
	strncpy(location->name, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, location->name);

	json = cJSON_GetObjectItem(cJSON_location, "country");
	strncpy(location->country, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, location->country);

	json = cJSON_GetObjectItem(cJSON_location, "path");
	strncpy(location->path, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, location->path);

	json = cJSON_GetObjectItem(cJSON_location, "timezone");
	strncpy(location->timezone, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, location->timezone);

	json = cJSON_GetObjectItem(cJSON_location, "timezone_offset");
	strncpy(location->timezone_offset, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, location->timezone_offset);

	printf("%s, %s\n", __func__, cJSON_GetStringValue(json));

	return 0;
}

int parse_weather_daily_data(cJSON *cJSON_daily, weather_day_t *daily)
{
	cJSON *json = NULL;
	printf("%s, %s\n", __func__, cJSON_Print(cJSON_daily));

	json = cJSON_GetObjectItem(cJSON_daily, "date");
	strncpy(daily->date, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->date);

	json = cJSON_GetObjectItem(cJSON_daily, "text_day");
	strncpy(daily->text_day, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->text_day);

	json = cJSON_GetObjectItem(cJSON_daily, "code_day");
	strncpy(daily->code_day, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->code_day);

	json = cJSON_GetObjectItem(cJSON_daily, "text_night");
	strncpy(daily->text_night, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->text_night);

	json = cJSON_GetObjectItem(cJSON_daily, "code_night");
	strncpy(daily->code_night, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->code_night);

	json = cJSON_GetObjectItem(cJSON_daily, "high");
	strncpy(daily->high, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->high);

	json = cJSON_GetObjectItem(cJSON_daily, "low");
	strncpy(daily->low, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->low);

	json = cJSON_GetObjectItem(cJSON_daily, "rainfall");
	strncpy(daily->rainfall, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->rainfall);

	json = cJSON_GetObjectItem(cJSON_daily, "precip");
	strncpy(daily->precip, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->precip);

	json = cJSON_GetObjectItem(cJSON_daily, "wind_direction");
	strncpy(daily->wind_direction, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->wind_direction);

	json = cJSON_GetObjectItem(cJSON_daily, "wind_direction_degree");
	strncpy(daily->wind_direction_degree, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->wind_direction_degree);

	json = cJSON_GetObjectItem(cJSON_daily, "wind_speed");
	strncpy(daily->wind_speed, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->wind_speed);

	json = cJSON_GetObjectItem(cJSON_daily, "wind_scale");
	strncpy(daily->wind_scale, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->wind_scale);

	json = cJSON_GetObjectItem(cJSON_daily, "humidity");
	strncpy(daily->humidity, cJSON_GetStringValue(json), 32);
	printf("%s, %s\n", __func__, daily->humidity);

	return 0;
}

int parse_weather_data(void)
{
	cJSON *json_init = NULL;
	cJSON *json = NULL;
	cJSON *location = NULL;
	cJSON *daily_array = NULL;
	cJSON *daily[3] = { 0 };
	int i = 0;

	json = cJSON_Parse(data);
	if (!json) {
		perror("cJSON_Parse failed!\n");
		return -1;
	}

	json_init = cJSON_GetObjectItem(json, "results");
	json = cJSON_GetArrayItem(json_init, 0);
	location = cJSON_GetObjectItem(json, "location");
	parse_weather_location(location, &weather.location);

	daily_array = cJSON_GetObjectItem(json, "daily");

	memset(&weather, 0, sizeof(weather));

	for (i = 0; i < 3; i++) {
		daily[i] = cJSON_GetArrayItem(daily_array, i);
		parse_weather_daily_data(daily[i], &weather.daily[i]);
	}

	cJSON_Delete(json_init);

	return 0;
}

int main(int argc, char *argv[])
{
	get_weather_from_web();

	parse_weather_data();

	return 0;
}

