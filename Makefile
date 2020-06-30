all:
	gcc weather_report.c cJSON.c -o report

clean:
	@rm report -rf
