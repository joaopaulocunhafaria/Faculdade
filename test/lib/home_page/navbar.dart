import 'package:flutter/material.dart';

class NavBar extends StatelessWidget {
  const NavBar({super.key});

  @override
  Widget build(BuildContext context) {
    return Drawer(
      backgroundColor: Color.fromRGBO(221, 186, 255, 1),
      child: ListView(
        children: [
          UserAccountsDrawerHeader(
            accountName: Text("Joao"),
            accountEmail: Text('joaopaulofaria98@gmail.com'),
            
            
          
          )
        ],
      ),
    );
  }
}
