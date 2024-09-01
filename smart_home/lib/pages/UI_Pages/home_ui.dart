import 'package:flutter/material.dart';
import 'led_ui.dart';
import 'door_ui.dart';

class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Control Your Home'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            IconButton(
              icon: const Icon(Icons.lightbulb_outline),
              iconSize: 90,
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => LedPage()),
                );
              },
            ),
            const SizedBox(height: 35),
            IconButton(
              icon: const Icon(Icons.door_back_door_outlined),
              iconSize: 90,
              onPressed: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => DoorPage()),
                );
              },
            ),
          ],
        ),
      ),
    );
  }
}
