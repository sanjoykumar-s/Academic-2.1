import java.io.*;
import java.text.*;
import java.util.*;

public class StudentList {
    public static void main(String[] args) {

        if(args.length!=1)
        {
            System.out.println(Constant.errorMessage);
            return;
        }
//		Check arguments
        if (args[0].equals(Constant.displayCommand)) {
            System.out.println(Constant.startMessage);
            try {
                String line = getString();
                String names[] = line.split(",");
                for (String name : names) {
                    System.out.println(name.trim());
                }
            } catch (Exception e) {
            }
            System.out.println(Constant.endMessage);
        } else if (args[0].equals(Constant.randomPrintCommand)) {
            System.out.println(Constant.startMessage);
            try {
                String line = getString();
                String names[] = line.split(",");

                int randomIndex = (int) ((Math.random() * ((names.length-1) - 0)));
                System.out.println(names[randomIndex].trim());
            } catch (Exception e) {
            }
            System.out.println(Constant.endMessage);
        } else if (args[0].contains("+")) {
            System.out.println(Constant.startMessage);
            try {
                BufferedWriter bufferedReader = getBufferedWriter();
                String subStringToAdd = args[0].substring(1);
                Date date = new Date();
                String timeFormat = "dd/mm/yyyy-hh:mm:ss a";
                DateFormat dateFormat = new SimpleDateFormat(timeFormat);
                String formatedDate = dateFormat.format(date);
                bufferedReader.write(", " + subStringToAdd + "\nList last updated on " + formatedDate);
                bufferedReader.close();
            } catch (Exception e) {
            }

            System.out.println(Constant.endMessage);
        } else if (args[0].contains("?")) {
            System.out.println(Constant.startMessage);
            try {
                String line = getString();
                String names[] = line.split(",");
                boolean done = false;
                String subStringToAdd = args[0].substring(1);
                for (int id = 0; id < names.length && !done; id++) {
                    if (names[id].trim().equals(subStringToAdd)) {
                        System.out.println("We found it!");
                        done = true;
                    }
                }
            } catch (Exception e) {
            }
            System.out.println(Constant.endMessage);
        } else if (args[0].contains("c")) {
            System.out.println(Constant.startMessage);
            try {
                String line = getString();
                char alphabates[] = line.toCharArray();
                int count = 0;
                for (char space : alphabates) {
                    if (space == ' ') {
                        count++;
                    }
                }
                System.out.println(count+1 + " word(s) found ");
            } catch (Exception e) {
            }
            System.out.println(Constant.endMessage);
        } else {
            System.out.println(Constant.errorMessage);
        }
    }

    private static BufferedWriter getBufferedWriter() throws IOException {
        BufferedWriter bufferedReader = new BufferedWriter(
                new FileWriter(Constant.inputFile, true));
        return bufferedReader;
    }

    private static String getString() throws IOException {
        BufferedReader bufferedReader = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(Constant.inputFile)));
        return bufferedReader.readLine();
    }
}
