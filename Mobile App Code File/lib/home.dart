import 'package:flutter/material.dart';
import 'package:movie_app/Loginscreen.dart';

const apiKey = 'e7240cc3ba10b382efe00b0c7dc5608f';

void main() {
  runApp(const MaterialApp(
    home: MovieApp(),
  ));
}

class MovieApp extends StatefulWidget {
  const MovieApp({super.key});

  @override
  State<MovieApp> createState() => _MovieAppState();
}

class _MovieAppState extends State<MovieApp> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Color(0xFF272829),
        centerTitle: true,
        title: const Text(
          "CleanAir",
          style: TextStyle(
            color: Color.fromARGB(255, 0, 217, 255),
          ),
        ),
        leading: IconButton(
            icon: Icon(Icons.arrow_back),
            onPressed: () {
              Navigator.push(context,
                  MaterialPageRoute(builder: (context) => const Loginscreen()));
            }),
      ),
      body: Container(
        decoration: BoxDecoration(
          image: DecorationImage(
            image: AssetImage('images/bb.jpg'),
            fit: BoxFit.cover,
          ),
        ),
      ),
    );
  }
}
