from wheater_station.wheater_station.core.sensors.sensor_base import Sensor


if __name__ == "__main__":
    sensor = Sensor(name="TEMP")
    print(sensor.counts_to_voltage(3011))