/*
 * CS 61C Fall 2013 Project 1
 *
 * DoublePair.java is a class which stores two doubles and 
 * implements the Writable interface. It can be used as a 
 * custom value for Hadoop. To use this as a key, you can
 * choose to implement the WritableComparable interface,
 * although that is not necessary for credit.
 */


import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;

import org.apache.hadoop.io.WritableComparable;
//paste something above


import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

import org.apache.hadoop.io.Writable;

public class DoublePair implements WritableComparable<DoublePair> {
    // Declare any variables here
    private double aw;
    private double sw;
    /**
     * Constructs a DoublePair with both doubles set to zero.
     */
    public DoublePair() {
        this(0.0, 0.0);

    }

    /**
     * Constructs a DoublePair containing double1 and double2.
     */ 
    public DoublePair(double double1, double double2) {
        // YOUR CODE HERE
        this.aw = double1;
        this.sw = double2;
    }

    /**
     * Returns the value of the first double.
     */
    public double getDouble1() {
        // YOUR CODE HERE
        return aw;
    }

    /**
     * Returns the value of the second double.
     */
    public double getDouble2() {
        // YOUR CODE HERE
        return sw;
    }

    /**
     * Sets the first double to val.
     */
    public void setDouble1(double val) {
        // YOUR CODE HERE
        this.aw = val;

    }

    /**
     * Sets the second double to val.
     */
    public void setDouble2(double val) {
        // YOUR CODE HERE
        this.sw = val;
        
    }

    /**
     * write() is required for implementing Writable.
     */
    public void write(DataOutput out) throws IOException {
        // YOUR CODE HERE
        out.writeDouble(aw);
        out.writeDouble(sw);
    }

    /**
     * readFields() is required for implementing Writable.
     */
    public void readFields(DataInput in) throws IOException {
        // YOUR CODE HERE
        aw = in.readDouble();
        sw = in.readDouble();

    }

    public int hashCode(){
        int hash = 17;
        hash = hash * 31 + new Double(aw).hashCode();
        hash = hash * 31 + new Double(sw).hashCode();
        return hash;
    }

    public int compareTo(DoublePair o){
        if (this.sw < o.getDouble2()){
            return -1;
        }
        else if(this.sw > o.getDouble2()) {
            return 1;
        }
        else{
            if (this.aw > o.getDouble1()){
                return -1;
            }
            else if(this.aw < o.getDouble1()){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    public String toString(){
        return "[" + Double.toString(aw) + ", " + Double.toString(sw) + "]";
    }
}
