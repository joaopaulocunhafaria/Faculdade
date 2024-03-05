import 'package:flutter/material.dart';
import 'package:test/home_page/slide_image.dart';
import 'package:test/show_products/product_model.dart';

class ShowProduct extends StatefulWidget {
    ShowProduct({super.key, required this.product});

  final Product product;
  final PageController _pageController = PageController(viewportFraction: 0.99);


  @override
  State<ShowProduct> createState() => _ShowProductState(product: product);
}

class _ShowProductState extends State<ShowProduct> {
  final Product product;
  final PageController _pageController = PageController(viewportFraction: 0.99);

  _ShowProductState({required this.product});

 
 
 
  @override
  Widget build(BuildContext context) {
    return   Scaffold(
      body: Column(
        children: [
          Text("Products Label"),
          Text("Products name"),
          Container(
            height: 120,
            child: PageView.builder(
              controller: _pageController,
              itemCount: product.images.length,
              itemBuilder: (_, currentIndex) {
                return SlideImage(
                  image: product.images[currentIndex]['image'],
                  body: _buildBullets(),
                );
              },
            ),
          )
        ],
      ),
    );
  }
}
