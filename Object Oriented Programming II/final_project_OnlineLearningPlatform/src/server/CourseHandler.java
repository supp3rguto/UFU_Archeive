package server;

import java.io.IOException;
import java.io.OutputStream;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.HttpExchange;
import decorator.BasicCourse;
import decorator.CertificateDecorator;
import decorator.Course;

public class CourseHandler implements HttpHandler {
    @Override
    public void handle(HttpExchange exchange) throws IOException {
        if ("GET".equals(exchange.getRequestMethod())) {
            Course basicCourse = new BasicCourse();
            Course certifiedCourse = new CertificateDecorator(basicCourse);

            String response = "<h1>Descrição do curso: " + certifiedCourse.getDescription() + "</h1>"
                    + "<p>Preço: $" + certifiedCourse.getPrice() + "</p>";

            exchange.sendResponseHeaders(200, response.length());
            OutputStream os = exchange.getResponseBody();
            os.write(response.getBytes());
            os.close();
        } else {
            exchange.sendResponseHeaders(405, -1);
        }
    }
}
