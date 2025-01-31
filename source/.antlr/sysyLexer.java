// Generated from /home/william/compiler/MyCompiler/source/sysy.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class sysyLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T_CONST=11, T_INT=12, T_VOID=13, T_IF=14, T_WHILE=15, T_BREAK=16, 
		T_CONTINUE=17, T_RETURN=18, T_ADD=19, T_SUB=20, T_MUL=21, T_DIV=22, T_MOD=23, 
		T_LT=24, T_GT=25, T_LE=26, T_GE=27, T_EQ=28, T_NE=29, T_AND=30, T_OR=31, 
		T_NOT=32, T_DEC_CONST=33, T_OCT_CONST=34, T_HEX_CONST=35, T_ID=36, WS=37, 
		LineComment=38, MultiLineComment=39;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T_CONST", "T_INT", "T_VOID", "T_IF", "T_WHILE", "T_BREAK", "T_CONTINUE", 
			"T_RETURN", "T_ADD", "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_LT", "T_GT", 
			"T_LE", "T_GE", "T_EQ", "T_NE", "T_AND", "T_OR", "T_NOT", "T_DEC_CONST", 
			"T_OCT_CONST", "T_HEX_CONST", "T_ID", "WS", "LineComment", "MultiLineComment"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "','", "';'", "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", 
			"'else'", "'const'", "'int'", "'void'", "'if'", "'while'", "'break'", 
			"'continue'", "'return'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", 
			"'<='", "'>='", "'=='", "'!='", "'&&'", "'||'", "'!'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, "T_CONST", 
			"T_INT", "T_VOID", "T_IF", "T_WHILE", "T_BREAK", "T_CONTINUE", "T_RETURN", 
			"T_ADD", "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_LT", "T_GT", "T_LE", 
			"T_GE", "T_EQ", "T_NE", "T_AND", "T_OR", "T_NOT", "T_DEC_CONST", "T_OCT_CONST", 
			"T_HEX_CONST", "T_ID", "WS", "LineComment", "MultiLineComment"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public sysyLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "sysy.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\'\u00f7\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002"+
		"\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002"+
		"\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0002"+
		"\u0015\u0007\u0015\u0002\u0016\u0007\u0016\u0002\u0017\u0007\u0017\u0002"+
		"\u0018\u0007\u0018\u0002\u0019\u0007\u0019\u0002\u001a\u0007\u001a\u0002"+
		"\u001b\u0007\u001b\u0002\u001c\u0007\u001c\u0002\u001d\u0007\u001d\u0002"+
		"\u001e\u0007\u001e\u0002\u001f\u0007\u001f\u0002 \u0007 \u0002!\u0007"+
		"!\u0002\"\u0007\"\u0002#\u0007#\u0002$\u0007$\u0002%\u0007%\u0002&\u0007"+
		"&\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002"+
		"\u0001\u0003\u0001\u0003\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001"+
		"\t\u0001\t\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001"+
		"\f\u0001\f\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e"+
		"\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001\u000f"+
		"\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010\u0001\u0010"+
		"\u0001\u0010\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011\u0001\u0011"+
		"\u0001\u0011\u0001\u0011\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013"+
		"\u0001\u0014\u0001\u0014\u0001\u0015\u0001\u0015\u0001\u0016\u0001\u0016"+
		"\u0001\u0017\u0001\u0017\u0001\u0018\u0001\u0018\u0001\u0019\u0001\u0019"+
		"\u0001\u0019\u0001\u001a\u0001\u001a\u0001\u001a\u0001\u001b\u0001\u001b"+
		"\u0001\u001b\u0001\u001c\u0001\u001c\u0001\u001c\u0001\u001d\u0001\u001d"+
		"\u0001\u001d\u0001\u001e\u0001\u001e\u0001\u001e\u0001\u001f\u0001\u001f"+
		"\u0001 \u0001 \u0005 \u00b9\b \n \f \u00bc\t \u0001!\u0001!\u0005!\u00c0"+
		"\b!\n!\f!\u00c3\t!\u0001\"\u0001\"\u0001\"\u0001\"\u0003\"\u00c9\b\"\u0001"+
		"\"\u0005\"\u00cc\b\"\n\"\f\"\u00cf\t\"\u0001#\u0001#\u0005#\u00d3\b#\n"+
		"#\f#\u00d6\t#\u0001$\u0004$\u00d9\b$\u000b$\f$\u00da\u0001$\u0001$\u0001"+
		"%\u0001%\u0001%\u0001%\u0005%\u00e3\b%\n%\f%\u00e6\t%\u0001%\u0001%\u0001"+
		"&\u0001&\u0001&\u0001&\u0005&\u00ee\b&\n&\f&\u00f1\t&\u0001&\u0001&\u0001"+
		"&\u0001&\u0001&\u0001\u00ef\u0000\'\u0001\u0001\u0003\u0002\u0005\u0003"+
		"\u0007\u0004\t\u0005\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015"+
		"\u000b\u0017\f\u0019\r\u001b\u000e\u001d\u000f\u001f\u0010!\u0011#\u0012"+
		"%\u0013\'\u0014)\u0015+\u0016-\u0017/\u00181\u00193\u001a5\u001b7\u001c"+
		"9\u001d;\u001e=\u001f? A!C\"E#G$I%K&M\'\u0001\u0000\b\u0001\u000019\u0001"+
		"\u000009\u0001\u000007\u0003\u000009AFaf\u0003\u0000AZ__az\u0004\u0000"+
		"09AZ__az\u0003\u0000\t\n\r\r  \u0002\u0000\n\n\r\r\u00fe\u0000\u0001\u0001"+
		"\u0000\u0000\u0000\u0000\u0003\u0001\u0000\u0000\u0000\u0000\u0005\u0001"+
		"\u0000\u0000\u0000\u0000\u0007\u0001\u0000\u0000\u0000\u0000\t\u0001\u0000"+
		"\u0000\u0000\u0000\u000b\u0001\u0000\u0000\u0000\u0000\r\u0001\u0000\u0000"+
		"\u0000\u0000\u000f\u0001\u0000\u0000\u0000\u0000\u0011\u0001\u0000\u0000"+
		"\u0000\u0000\u0013\u0001\u0000\u0000\u0000\u0000\u0015\u0001\u0000\u0000"+
		"\u0000\u0000\u0017\u0001\u0000\u0000\u0000\u0000\u0019\u0001\u0000\u0000"+
		"\u0000\u0000\u001b\u0001\u0000\u0000\u0000\u0000\u001d\u0001\u0000\u0000"+
		"\u0000\u0000\u001f\u0001\u0000\u0000\u0000\u0000!\u0001\u0000\u0000\u0000"+
		"\u0000#\u0001\u0000\u0000\u0000\u0000%\u0001\u0000\u0000\u0000\u0000\'"+
		"\u0001\u0000\u0000\u0000\u0000)\u0001\u0000\u0000\u0000\u0000+\u0001\u0000"+
		"\u0000\u0000\u0000-\u0001\u0000\u0000\u0000\u0000/\u0001\u0000\u0000\u0000"+
		"\u00001\u0001\u0000\u0000\u0000\u00003\u0001\u0000\u0000\u0000\u00005"+
		"\u0001\u0000\u0000\u0000\u00007\u0001\u0000\u0000\u0000\u00009\u0001\u0000"+
		"\u0000\u0000\u0000;\u0001\u0000\u0000\u0000\u0000=\u0001\u0000\u0000\u0000"+
		"\u0000?\u0001\u0000\u0000\u0000\u0000A\u0001\u0000\u0000\u0000\u0000C"+
		"\u0001\u0000\u0000\u0000\u0000E\u0001\u0000\u0000\u0000\u0000G\u0001\u0000"+
		"\u0000\u0000\u0000I\u0001\u0000\u0000\u0000\u0000K\u0001\u0000\u0000\u0000"+
		"\u0000M\u0001\u0000\u0000\u0000\u0001O\u0001\u0000\u0000\u0000\u0003Q"+
		"\u0001\u0000\u0000\u0000\u0005S\u0001\u0000\u0000\u0000\u0007U\u0001\u0000"+
		"\u0000\u0000\tW\u0001\u0000\u0000\u0000\u000bY\u0001\u0000\u0000\u0000"+
		"\r[\u0001\u0000\u0000\u0000\u000f]\u0001\u0000\u0000\u0000\u0011_\u0001"+
		"\u0000\u0000\u0000\u0013a\u0001\u0000\u0000\u0000\u0015f\u0001\u0000\u0000"+
		"\u0000\u0017l\u0001\u0000\u0000\u0000\u0019p\u0001\u0000\u0000\u0000\u001b"+
		"u\u0001\u0000\u0000\u0000\u001dx\u0001\u0000\u0000\u0000\u001f~\u0001"+
		"\u0000\u0000\u0000!\u0084\u0001\u0000\u0000\u0000#\u008d\u0001\u0000\u0000"+
		"\u0000%\u0094\u0001\u0000\u0000\u0000\'\u0096\u0001\u0000\u0000\u0000"+
		")\u0098\u0001\u0000\u0000\u0000+\u009a\u0001\u0000\u0000\u0000-\u009c"+
		"\u0001\u0000\u0000\u0000/\u009e\u0001\u0000\u0000\u00001\u00a0\u0001\u0000"+
		"\u0000\u00003\u00a2\u0001\u0000\u0000\u00005\u00a5\u0001\u0000\u0000\u0000"+
		"7\u00a8\u0001\u0000\u0000\u00009\u00ab\u0001\u0000\u0000\u0000;\u00ae"+
		"\u0001\u0000\u0000\u0000=\u00b1\u0001\u0000\u0000\u0000?\u00b4\u0001\u0000"+
		"\u0000\u0000A\u00b6\u0001\u0000\u0000\u0000C\u00bd\u0001\u0000\u0000\u0000"+
		"E\u00c8\u0001\u0000\u0000\u0000G\u00d0\u0001\u0000\u0000\u0000I\u00d8"+
		"\u0001\u0000\u0000\u0000K\u00de\u0001\u0000\u0000\u0000M\u00e9\u0001\u0000"+
		"\u0000\u0000OP\u0005,\u0000\u0000P\u0002\u0001\u0000\u0000\u0000QR\u0005"+
		";\u0000\u0000R\u0004\u0001\u0000\u0000\u0000ST\u0005[\u0000\u0000T\u0006"+
		"\u0001\u0000\u0000\u0000UV\u0005]\u0000\u0000V\b\u0001\u0000\u0000\u0000"+
		"WX\u0005=\u0000\u0000X\n\u0001\u0000\u0000\u0000YZ\u0005{\u0000\u0000"+
		"Z\f\u0001\u0000\u0000\u0000[\\\u0005}\u0000\u0000\\\u000e\u0001\u0000"+
		"\u0000\u0000]^\u0005(\u0000\u0000^\u0010\u0001\u0000\u0000\u0000_`\u0005"+
		")\u0000\u0000`\u0012\u0001\u0000\u0000\u0000ab\u0005e\u0000\u0000bc\u0005"+
		"l\u0000\u0000cd\u0005s\u0000\u0000de\u0005e\u0000\u0000e\u0014\u0001\u0000"+
		"\u0000\u0000fg\u0005c\u0000\u0000gh\u0005o\u0000\u0000hi\u0005n\u0000"+
		"\u0000ij\u0005s\u0000\u0000jk\u0005t\u0000\u0000k\u0016\u0001\u0000\u0000"+
		"\u0000lm\u0005i\u0000\u0000mn\u0005n\u0000\u0000no\u0005t\u0000\u0000"+
		"o\u0018\u0001\u0000\u0000\u0000pq\u0005v\u0000\u0000qr\u0005o\u0000\u0000"+
		"rs\u0005i\u0000\u0000st\u0005d\u0000\u0000t\u001a\u0001\u0000\u0000\u0000"+
		"uv\u0005i\u0000\u0000vw\u0005f\u0000\u0000w\u001c\u0001\u0000\u0000\u0000"+
		"xy\u0005w\u0000\u0000yz\u0005h\u0000\u0000z{\u0005i\u0000\u0000{|\u0005"+
		"l\u0000\u0000|}\u0005e\u0000\u0000}\u001e\u0001\u0000\u0000\u0000~\u007f"+
		"\u0005b\u0000\u0000\u007f\u0080\u0005r\u0000\u0000\u0080\u0081\u0005e"+
		"\u0000\u0000\u0081\u0082\u0005a\u0000\u0000\u0082\u0083\u0005k\u0000\u0000"+
		"\u0083 \u0001\u0000\u0000\u0000\u0084\u0085\u0005c\u0000\u0000\u0085\u0086"+
		"\u0005o\u0000\u0000\u0086\u0087\u0005n\u0000\u0000\u0087\u0088\u0005t"+
		"\u0000\u0000\u0088\u0089\u0005i\u0000\u0000\u0089\u008a\u0005n\u0000\u0000"+
		"\u008a\u008b\u0005u\u0000\u0000\u008b\u008c\u0005e\u0000\u0000\u008c\""+
		"\u0001\u0000\u0000\u0000\u008d\u008e\u0005r\u0000\u0000\u008e\u008f\u0005"+
		"e\u0000\u0000\u008f\u0090\u0005t\u0000\u0000\u0090\u0091\u0005u\u0000"+
		"\u0000\u0091\u0092\u0005r\u0000\u0000\u0092\u0093\u0005n\u0000\u0000\u0093"+
		"$\u0001\u0000\u0000\u0000\u0094\u0095\u0005+\u0000\u0000\u0095&\u0001"+
		"\u0000\u0000\u0000\u0096\u0097\u0005-\u0000\u0000\u0097(\u0001\u0000\u0000"+
		"\u0000\u0098\u0099\u0005*\u0000\u0000\u0099*\u0001\u0000\u0000\u0000\u009a"+
		"\u009b\u0005/\u0000\u0000\u009b,\u0001\u0000\u0000\u0000\u009c\u009d\u0005"+
		"%\u0000\u0000\u009d.\u0001\u0000\u0000\u0000\u009e\u009f\u0005<\u0000"+
		"\u0000\u009f0\u0001\u0000\u0000\u0000\u00a0\u00a1\u0005>\u0000\u0000\u00a1"+
		"2\u0001\u0000\u0000\u0000\u00a2\u00a3\u0005<\u0000\u0000\u00a3\u00a4\u0005"+
		"=\u0000\u0000\u00a44\u0001\u0000\u0000\u0000\u00a5\u00a6\u0005>\u0000"+
		"\u0000\u00a6\u00a7\u0005=\u0000\u0000\u00a76\u0001\u0000\u0000\u0000\u00a8"+
		"\u00a9\u0005=\u0000\u0000\u00a9\u00aa\u0005=\u0000\u0000\u00aa8\u0001"+
		"\u0000\u0000\u0000\u00ab\u00ac\u0005!\u0000\u0000\u00ac\u00ad\u0005=\u0000"+
		"\u0000\u00ad:\u0001\u0000\u0000\u0000\u00ae\u00af\u0005&\u0000\u0000\u00af"+
		"\u00b0\u0005&\u0000\u0000\u00b0<\u0001\u0000\u0000\u0000\u00b1\u00b2\u0005"+
		"|\u0000\u0000\u00b2\u00b3\u0005|\u0000\u0000\u00b3>\u0001\u0000\u0000"+
		"\u0000\u00b4\u00b5\u0005!\u0000\u0000\u00b5@\u0001\u0000\u0000\u0000\u00b6"+
		"\u00ba\u0007\u0000\u0000\u0000\u00b7\u00b9\u0007\u0001\u0000\u0000\u00b8"+
		"\u00b7\u0001\u0000\u0000\u0000\u00b9\u00bc\u0001\u0000\u0000\u0000\u00ba"+
		"\u00b8\u0001\u0000\u0000\u0000\u00ba\u00bb\u0001\u0000\u0000\u0000\u00bb"+
		"B\u0001\u0000\u0000\u0000\u00bc\u00ba\u0001\u0000\u0000\u0000\u00bd\u00c1"+
		"\u00050\u0000\u0000\u00be\u00c0\u0007\u0002\u0000\u0000\u00bf\u00be\u0001"+
		"\u0000\u0000\u0000\u00c0\u00c3\u0001\u0000\u0000\u0000\u00c1\u00bf\u0001"+
		"\u0000\u0000\u0000\u00c1\u00c2\u0001\u0000\u0000\u0000\u00c2D\u0001\u0000"+
		"\u0000\u0000\u00c3\u00c1\u0001\u0000\u0000\u0000\u00c4\u00c5\u00050\u0000"+
		"\u0000\u00c5\u00c9\u0005x\u0000\u0000\u00c6\u00c7\u00050\u0000\u0000\u00c7"+
		"\u00c9\u0005X\u0000\u0000\u00c8\u00c4\u0001\u0000\u0000\u0000\u00c8\u00c6"+
		"\u0001\u0000\u0000\u0000\u00c9\u00cd\u0001\u0000\u0000\u0000\u00ca\u00cc"+
		"\u0007\u0003\u0000\u0000\u00cb\u00ca\u0001\u0000\u0000\u0000\u00cc\u00cf"+
		"\u0001\u0000\u0000\u0000\u00cd\u00cb\u0001\u0000\u0000\u0000\u00cd\u00ce"+
		"\u0001\u0000\u0000\u0000\u00ceF\u0001\u0000\u0000\u0000\u00cf\u00cd\u0001"+
		"\u0000\u0000\u0000\u00d0\u00d4\u0007\u0004\u0000\u0000\u00d1\u00d3\u0007"+
		"\u0005\u0000\u0000\u00d2\u00d1\u0001\u0000\u0000\u0000\u00d3\u00d6\u0001"+
		"\u0000\u0000\u0000\u00d4\u00d2\u0001\u0000\u0000\u0000\u00d4\u00d5\u0001"+
		"\u0000\u0000\u0000\u00d5H\u0001\u0000\u0000\u0000\u00d6\u00d4\u0001\u0000"+
		"\u0000\u0000\u00d7\u00d9\u0007\u0006\u0000\u0000\u00d8\u00d7\u0001\u0000"+
		"\u0000\u0000\u00d9\u00da\u0001\u0000\u0000\u0000\u00da\u00d8\u0001\u0000"+
		"\u0000\u0000\u00da\u00db\u0001\u0000\u0000\u0000\u00db\u00dc\u0001\u0000"+
		"\u0000\u0000\u00dc\u00dd\u0006$\u0000\u0000\u00ddJ\u0001\u0000\u0000\u0000"+
		"\u00de\u00df\u0005/\u0000\u0000\u00df\u00e0\u0005/\u0000\u0000\u00e0\u00e4"+
		"\u0001\u0000\u0000\u0000\u00e1\u00e3\b\u0007\u0000\u0000\u00e2\u00e1\u0001"+
		"\u0000\u0000\u0000\u00e3\u00e6\u0001\u0000\u0000\u0000\u00e4\u00e2\u0001"+
		"\u0000\u0000\u0000\u00e4\u00e5\u0001\u0000\u0000\u0000\u00e5\u00e7\u0001"+
		"\u0000\u0000\u0000\u00e6\u00e4\u0001\u0000\u0000\u0000\u00e7\u00e8\u0006"+
		"%\u0000\u0000\u00e8L\u0001\u0000\u0000\u0000\u00e9\u00ea\u0005/\u0000"+
		"\u0000\u00ea\u00eb\u0005*\u0000\u0000\u00eb\u00ef\u0001\u0000\u0000\u0000"+
		"\u00ec\u00ee\t\u0000\u0000\u0000\u00ed\u00ec\u0001\u0000\u0000\u0000\u00ee"+
		"\u00f1\u0001\u0000\u0000\u0000\u00ef\u00f0\u0001\u0000\u0000\u0000\u00ef"+
		"\u00ed\u0001\u0000\u0000\u0000\u00f0\u00f2\u0001\u0000\u0000\u0000\u00f1"+
		"\u00ef\u0001\u0000\u0000\u0000\u00f2\u00f3\u0005*\u0000\u0000\u00f3\u00f4"+
		"\u0005/\u0000\u0000\u00f4\u00f5\u0001\u0000\u0000\u0000\u00f5\u00f6\u0006"+
		"&\u0000\u0000\u00f6N\u0001\u0000\u0000\u0000\t\u0000\u00ba\u00c1\u00c8"+
		"\u00cd\u00d4\u00da\u00e4\u00ef\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}