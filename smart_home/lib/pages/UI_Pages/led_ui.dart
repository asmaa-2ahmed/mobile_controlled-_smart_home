import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';
import 'dart:async';
import 'package:fluttertoast/fluttertoast.dart';

import 'package:smart_home_firebase/pages/Auth_Pages/auth_service.dart';

import 'door_ui.dart';

class LedPage extends StatefulWidget {
  @override
  _LedPageState createState() => _LedPageState();
}

class _LedPageState extends State<LedPage> {
  late BluetoothConnection _connection;
  bool _isConnected = false;
  bool _isLedOn = false;

  Future<void> _connect() async {
    try {
      _connection = await BluetoothConnection.toAddress("98:D3:71:F6:D1:9B");
      Fluttertoast.showToast(msg: 'Connected to the Bluetooth device');

      setState(() {
        _isConnected = true;
      });

      // Listen for incoming data
      _connection.input!.listen((data) {
        // Handle the received data (e.g., verify acknowledgment)
      }).onDone(() {
        setState(() {
          _isConnected = false;
        });
      });
    } catch (exception) {
      Fluttertoast.showToast(msg: 'Cannot connect, exception occurred');
      setState(() {
        _isConnected = false;
      });
    }
  }

  void _sendData(String data) async {
    if (_isConnected) {
      _connection.output.add(utf8.encode(data));
      await _connection.output.allSent;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Control Led'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text(
              _isLedOn ? 'LED is ON' : 'LED is OFF',
              style: const TextStyle(fontSize: 24),
            ),
            const SizedBox(height: 20),
            Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                ElevatedButton(
                  child: Row(
                    children: const [
                      Icon(Icons.lightbulb, color: Colors.green),
                      Text('TURN ON', style: TextStyle(fontSize: 20)),
                    ],
                  ),
                  onPressed: () {
                    _connect();
                    _sendData('1'); // Send command to turn LED on
                    setState(() {
                      _isLedOn = true;
                    });
                  },
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.greenAccent,
                    padding: const EdgeInsets.all(20),
                  ),
                ),
                const SizedBox(width: 20),
                ElevatedButton(
                  onPressed: () {
                    _connect();
                    _sendData('0'); // Send command to turn LED off
                    setState(() {
                      _isLedOn = false;
                    });
                  },
                  style: ElevatedButton.styleFrom(
                    backgroundColor: const Color.fromARGB(255, 239, 128, 128),
                    padding: const EdgeInsets.all(20),
                  ),
                  child: const Row(
                    children: [
                      Icon(Icons.lightbulb_outline, color: Colors.red),
                      Text('TURN OFF', style: TextStyle(fontSize: 20)),
                    ],
                  ),
                ),
              ],
            ),
          ],
        ),
      ),
      bottomNavigationBar: BottomNavigationBar(
        items: const [
          BottomNavigationBarItem(
            icon: Icon(Icons.lightbulb_outline),
            label: 'LED',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.doorbell_sharp),
            label: 'Door',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.logout),
            label: 'Sign Out',
          ),
        ],
        currentIndex: 0,
        onTap: (index) {
          if (index == 1) {
            Navigator.pushReplacement(
              context,
              MaterialPageRoute(builder: (context) => DoorPage()),
            );
          } else if (index == 2) {
            AuthService().signout(context: context);
          }
        },
      ),
    );
  }
}
