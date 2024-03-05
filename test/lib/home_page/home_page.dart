import 'dart:async';

import 'package:flutter/material.dart';
import 'package:test/home_page/clients_testimonial.dart';
import 'package:test/home_page/clothes_display.dart';
import 'package:test/home_page/navbar.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:test/home_page/newsletter.dart';
import 'package:test/home_page/slide_image.dart';
import 'package:test/login_page/login_page.dart';

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      resizeToAvoidBottomInset: true,
      drawer: NavBar(),
      appBar: AppBar(
          backgroundColor: const Color.fromRGBO(221, 186, 255, 1),
          title: Row(
            children: [
              Expanded(
                flex: 3,
                child: GestureDetector(
                  onTap: () {
                    print("container clicado");
                  },
                  child: Container(
                    padding: const EdgeInsets.only(left: 55),
                    child: const Text(
                      'LOJA',
                      style: TextStyle(
                          color: Color.fromRGBO(255, 95, 165, 1),
                          fontWeight: FontWeight.bold,
                          fontSize: 45.0,
                          fontFamily: 'Anton'),
                    ),
                  ),
                ),
              ),
              Expanded(
                  flex: 2,
                  child: Row(
                    children: [
                      IconButton(
                        icon: const Icon(Icons.account_circle_outlined),
                        onPressed: () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                                builder: (context) => const LoginPage()),
                          );
                        },
                      ),
                      IconButton(
                        icon: const Icon(Icons.shopping_cart_outlined),
                        onPressed: () {},
                      ),
                    ],
                  ))
            ],
          )),
      body: HomeScreen(),
    );
  }
}

class HomeScreen extends StatefulWidget {
  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  int _currentPage = 0;

  final List<Map<String, dynamic>> _listImage = [
    {'id': 0, 'image': "assets/images/image1.jpeg"},
    {'id': 1, 'image': "assets/images/image2.jpeg"},
    {'id': 2, 'image': "assets/images/image3.jpeg"}
  ];

  final PageController _pageController = PageController(viewportFraction: 0.99);

  final TextEditingController _searchControler = TextEditingController();
  int i = 0;
  @override
  void initState() {
    Timer.periodic(const Duration(seconds: 4), (Timer t) {
      if (i == (_listImage.length)) {
        i = 0;
      }
      setState(() {
        _pageController.jumpToPage(i);
        _currentPage = i;
        i++;
      });
    });
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Column(
        children: [
          const Divider(
            color: Colors.grey,
            thickness: 1.8,
            height: 2,
            indent: 0.0,
            endIndent: 0.0,
          ),

          Container(
            color: const Color.fromRGBO(236, 218, 254, 1),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Expanded(
                  child: Container(
                    color: const Color.fromRGBO(236, 218, 254, 1),
                    child: Center(
                      child: IconButton(
                        color: const Color.fromRGBO(236, 218, 254, 1),
                        icon: const FaIcon(
                          FontAwesomeIcons.whatsapp,
                          color: Colors.green,
                        ),
                        onPressed: () {},
                      ),
                    ),
                  ),
                ),
                Expanded(
                  child: Container(
                    color: const Color.fromRGBO(236, 218, 254, 1),
                    child: Center(
                      child: Container(
                        color: const Color.fromRGBO(236, 218, 254, 1),
                        child: TextField(
                          controller: _searchControler,
                          decoration: const InputDecoration(
                            hintText: 'Buscar',
                            border: InputBorder.none,
                          ),
                        ),
                      ),
                    ),
                  ),
                ),
                Expanded(
                  child: Container(
                    color: const Color.fromRGBO(236, 218, 254, 1),
                    child: const Center(
                      child: FaIcon(
                        FontAwesomeIcons.magnifyingGlass,
                        color: Colors.black,
                      ),
                    ),
                  ),
                ),
              ],
            ),
          ),
          const SizedBox(
            height: 5,
          ),
          Container(
            height: 120,
            child: PageView.builder(
              controller: _pageController,
              itemCount: _listImage.length,
              itemBuilder: (_, currentIndex) {
                return SlideImage(
                  image: _listImage[currentIndex]['image'],
                  body: _buildBullets(),
                );
              },
            ),
          ),
          const SizedBox(height: 10),
          const Text(
            'Destaques',
            style: TextStyle(
              color: Color.fromRGBO(255, 95, 165, 1),
              fontWeight: FontWeight.bold,
              fontSize: 30.0,
              fontFamily: 'Anton',
            ),
          ),
          const SizedBox(
              height: 10), // Adiciona um espaçamento entre os widgets
          const Row(
            crossAxisAlignment: CrossAxisAlignment.center,
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              ClothesDisplay(),
              SizedBox(
                width: 35,
              ),
              ClothesDisplay()
            ],
          ),
          const Testimonial(),
          const Newsletter(),
          Container(
            height: 80,
            color: const Color.fromARGB(255, 46, 82, 62),
            child: const Center(
                child: Text(
              "Some info about us",
              style: TextStyle(color: Colors.white, fontSize: 35),
            )),
          )
        ],
      ),
    );
  }

  Widget _buildBullets() {
    return Padding(
      padding: const EdgeInsets.all(8),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.end,
        children: [
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: _listImage.map((i) {
              return InkWell(
                onTap: () {
                  setState(() {
                    _pageController.jumpToPage(i['id']);
                    _currentPage = i['id'];
                  });
                },
                child: Container(
                  margin: const EdgeInsets.all(10),
                  width: 10,
                  height: 10,
                  decoration: BoxDecoration(
                      borderRadius: BorderRadius.circular(30),
                      color:
                          _currentPage == i['id'] ? Colors.white : Colors.grey),
                ),
              );
            }).toList(),
          ),
        ],
      ),
    );
  }
}
