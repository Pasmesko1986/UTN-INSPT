from core.sensors.sensor_base import Sensor

class TemperatureSensor(Sensor):
    __AMPLIFIER_GAIN__ = 2
    __VOLT_PER_GRADE__ = 0.01
    __DIODE_DROPT__=0.9
    name = 'TEMP'

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.name = 'TEMP'

    def convert_volt_to_celsius(self, voltage:int) -> int:
        value = ((voltage / self.__AMPLIFIER_GAIN__) - self.__DIODE_DROPT__) / self.__VOLT_PER_GRADE__
        return int(value)
    
    @staticmethod
    def read_once():
        t = TemperatureSensor()
        counts = t.single_read()
        voltage = t.counts_to_voltage(counts=counts)
        return t.convert_volt_to_celsius(voltage=voltage)