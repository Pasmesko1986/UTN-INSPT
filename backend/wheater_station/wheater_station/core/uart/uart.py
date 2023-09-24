import serial
from wheater_station.settings import BAUDRATE, SERIAL_PORT, SERIAL_TIMEOUT

class SerialUART:
    _instance = None

    def __new__(cls, port : str = SERIAL_PORT, baudrate : int = BAUDRATE, timeout : int = SERIAL_TIMEOUT) -> serial.Serial:
        if cls._instance is None:
            cls._instance = super(SerialUART, cls).__new__(cls)
            cls._instance.port = port
            cls._instance.baudrate = baudrate
            cls._instance.timeout = timeout
            cls._instance.serial = None
        return cls._instance

    def open_connection(self):
        if not self.serial or not self.serial.is_open:
            self.serial = serial.Serial(self.port, self.baudrate)
            print(f"Conexión abierta en el puerto {self.port} a {self.baudrate} baudios")

    def close_connection(self):
        if self.serial:
            self.serial.close()
            print(f"Conexión cerrada en el puerto {self.port}")

    def write_data(self, data : str):
        if self.serial:
            self.serial.write(data.encode('utf-8'))

    def read_data(self):
        if self.serial:
            received_data = self.serial.read()
            data_left = self.serial.inWaiting()
            received_data += self.serial.read(data_left)
            received_data = received_data.decode('utf-8')
            return received_data

# Uso del Singleton
if __name__ == "__main__":
    from time import sleep
    from datetime import datetime
    while 1:
        port_instance_1 = SerialUART()

        port_instance_1.open_connection()

        port_instance_1.write_data(f"Hola desde {port_instance_1.port}: {datetime.utcnow()}")
        sleep(0.03)
        data1 = port_instance_1.read_data()

        print(data1)

        port_instance_1.close_connection()